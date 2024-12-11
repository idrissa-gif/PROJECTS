package com.example.onlinefood;

import javafx.application.Platform;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.geometry.Insets;
import javafx.scene.Node;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.GridPane;
import javafx.stage.FileChooser;
import javafx.stage.Stage;

import java.io.ByteArrayInputStream;
import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.sql.*;
import java.util.logging.Level;
import java.util.logging.Logger;

public class DishOrderController {
    @FXML
    public TextField nameField;
    @FXML
    public TextField descriptionField;
    @FXML
    public TextField ingredientsField;
    @FXML
    public TextField priceField;

    public DatabaseConnector database = new DatabaseConnector();

    @FXML
    private TableView<Dish> DishTableView;
    @FXML
    public TableColumn<Dish, String> NameColumn;
    @FXML
    public TableColumn<Dish, String> DescriptionColumn;
    @FXML
    public TableColumn<Dish, String> IngredientsColumn;
    @FXML
    public TableColumn<Dish, Integer> PriceColumn;
    @FXML
    public TableColumn<Dish, Image> ImageColumn;

    @FXML
    private Tab deliverationTab;

    @FXML
    private ImageView selectedImageView;

    private SimpleDishFactory dishFactory = new SimpleDishFactory();

    @FXML
    public void displayPizzaTable() {
        try {
            Connection conn = database.getConnection();
            String query = "SELECT * FROM pizza_db.dish_tb";

            try (PreparedStatement stmt = conn.prepareStatement(query);
                 ResultSet rs = stmt.executeQuery()) {

                ObservableList<Dish> dishList = FXCollections.observableArrayList();

                while (rs.next()) {
                    String dishName = rs.getString("name");
                    String description = rs.getString("description");
                    String ingredients = rs.getString("ingredients");
                    int price = rs.getInt("price");
                    Blob imageBlob = rs.getBlob("image");

                    Image image = null;

                    if (imageBlob != null) {
                        try (InputStream inputStream = imageBlob.getBinaryStream()) {
                            byte[] imageBytes = inputStream.readAllBytes();
                            ByteArrayInputStream byteArrayInputStream = new ByteArrayInputStream(imageBytes);
                            image = new Image(byteArrayInputStream);
                        } catch (IOException e) {
                            Logger.getLogger(DishOrderController.class.getName()).log(Level.SEVERE, null, e);
                        }
                    }

                    Dish dish = new Dish(dishName, description, ingredients, price, image);
                    dishList.add(dish);
                }

                DishTableView.setItems(dishList);
                DishTableView.refresh(); // Add this line to refresh the TableView
            }
        } catch (SQLException e) {
            Logger.getLogger(DishOrderController.class.getName()).log(Level.SEVERE, null, e);
        }
    }

    @FXML
    public void initialize() {
        NameColumn.setCellValueFactory(new PropertyValueFactory<>("Name"));
        DescriptionColumn.setCellValueFactory(new PropertyValueFactory<>("Description"));
        IngredientsColumn.setCellValueFactory(new PropertyValueFactory<>("ingredients"));
        PriceColumn.setCellValueFactory(new PropertyValueFactory<>("price"));
        ImageColumn.setCellValueFactory(new PropertyValueFactory<>("image"));
        TableColumn<Dish, Void> editColumn = new TableColumn<>("Edit");
        TableColumn<Dish, Void> deleteColumn = new TableColumn<>("Delete");
        editColumn.setCellFactory(param -> new TableCell<>() {
            private final Button editButton = new Button("Edit");

            {
                editButton.setStyle("-fx-background-color: #4CAF50; -fx-text-fill: white;");
                editButton.setOnAction(event -> handleEditButton(getIndex()));
            }

            @Override
            protected void updateItem(Void item, boolean empty) {
                super.updateItem(item, empty);

                if (empty) {
                    setGraphic(null);
                } else {
                    setGraphic(editButton);
                }
            }
        });

        deleteColumn.setCellFactory(param -> new TableCell<>() {
            private final Button deleteButton = new Button("Delete");

            {
                deleteButton.setStyle("-fx-background-color: #FF0000; -fx-text-fill: white;");
                deleteButton.setOnAction(event -> handleDeleteButton(getIndex()));
            }

            @Override
            protected void updateItem(Void item, boolean empty) {
                super.updateItem(item, empty);

                if (empty) {
                    setGraphic(null);
                } else {
                    setGraphic(deleteButton);
                }
            }
        });

        ImageColumn.setCellFactory(param -> new TableCell<>() {
            private final ImageView imageView = new ImageView();
            {
                // Set preferred size for the image
                imageView.setFitHeight(50);
                imageView.setFitWidth(50);
            }

            @Override
            protected void updateItem(Image item, boolean empty) {
                super.updateItem(item, empty);

                if (empty || item == null) {
                    setGraphic(null);
                } else {
                    // Display the image in the ImageView
                    imageView.setImage(item);
                    setGraphic(imageView);
                }
            }
        });

        // Set an event handler for tab selection changes
        deliverationTab.setOnSelectionChanged(event -> {
            if (deliverationTab.isSelected()) {
                // When the Deliveration tab is selected, display all pizzas
                displayPizzaTable();
            }
        });

        DishTableView.getColumns().addAll(editColumn, deleteColumn);
    }

    private void handleEditButton(int index) {
        Dish selectedDish = DishTableView.getItems().get(index);

        // Create a custom dialog for editing a dish
        Dialog<Dish> editDialog = new Dialog<>();
        editDialog.setTitle("Edit Dish");

        // Set the button types
        ButtonType saveButtonType = new ButtonType("Save", ButtonBar.ButtonData.OK_DONE);
        editDialog.getDialogPane().getButtonTypes().addAll(saveButtonType, ButtonType.CANCEL);

        // Create a GridPane for the layout
        GridPane grid = new GridPane();
        grid.setHgap(10);
        grid.setVgap(10);
        grid.setPadding(new Insets(20, 150, 10, 10));

        // Create TextFields for each attribute
        TextField nameField = new TextField();
        nameField.setText(selectedDish.getName());
        TextField descriptionField = new TextField();
        descriptionField.setText(selectedDish.getDescription());
        TextField ingredientsField = new TextField();
        ingredientsField.setText(selectedDish.getIngredients());
        TextField priceField = new TextField();
        priceField.setText(String.valueOf(selectedDish.getPrice()));

        // Add TextFields to the GridPane
        grid.add(new Label("Name:"), 0, 0);
        grid.add(nameField, 1, 0);
        grid.add(new Label("Description:"), 0, 1);
        grid.add(descriptionField, 1, 1);
        grid.add(new Label("Ingredients:"), 0, 2);
        grid.add(ingredientsField, 1, 2);
        grid.add(new Label("Price:"), 0, 3);
        grid.add(priceField, 1, 3);

        // Enable/Disable Save button depending on whether a name is entered
        Node saveButton = editDialog.getDialogPane().lookupButton(saveButtonType);
        saveButton.setDisable(true);

        // Do some validation (e.g., enable the Save button only if the name is not empty)
        nameField.textProperty().addListener((observable, oldValue, newValue) -> {
            saveButton.setDisable(newValue.trim().isEmpty());
        });

        // Set the GridPane as the content of the dialog
        editDialog.getDialogPane().setContent(grid);

        // Request focus on the name field by default
        Platform.runLater(() -> nameField.requestFocus());

        // Convert the result to a Dish object when the Save button is clicked
        editDialog.setResultConverter(dialogButton -> {
            if (dialogButton == saveButtonType) {
                // Update the selected dish with the new values
                selectedDish.setName(nameField.getText());
                selectedDish.setDescription(descriptionField.getText());
                selectedDish.setIngredients(ingredientsField.getText());
                selectedDish.setPrice(Integer.parseInt(priceField.getText()));

                // You can also update the changes in the database if needed
                dishFactory.editDish(selectedDish);

                // Refresh the TableView
                DishTableView.refresh();

                // Show success message
                // showAlert(Alert.AlertType.INFORMATION, "Edit Successful", "Dish edited successfully!");

                return selectedDish;
            }
            return null;
        });

        // Show the dialog and wait for the user's input
        editDialog.showAndWait();
    }

    private void handleDeleteButton(int index) {
        // Implement your logic for handling the delete button click
        Dish selectedDish = DishTableView.getItems().get(index);
        // You can confirm deletion and then remove the selected dish from the table
        DishTableView.getItems().remove(index);
        dishFactory.deleteDish(selectedDish);
    }
    @FXML
    public void InsertPizza() {
        dishFactory.createDish(nameField.getText(), Integer.valueOf(priceField.getText()), ingredientsField.getText(), descriptionField.getText(), selectedImageView.getImage());
        nameField.setText("");
        priceField.setText("");
        ingredientsField.setText("");
        descriptionField.setText("");
        selectedImageView.setImage(null);
    }


    @FXML
    private void chooseImage(ActionEvent event) {
        FileChooser fileChooser = new FileChooser();
        fileChooser.getExtensionFilters().add(new FileChooser.ExtensionFilter("Image Files", "*.png", "*.jpg", "*.jpeg", "*.gif"));

        // Show open file dialog
        File selectedFile = fileChooser.showOpenDialog(new Stage());

        if (selectedFile != null) {
            // Load the selected image into the ImageView
            Image selectedImage = new Image(selectedFile.toURI().toString());
            selectedImageView.setImage(selectedImage);
        }
    }

}