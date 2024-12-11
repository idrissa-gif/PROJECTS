package com.example.onlinefood;


import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.sql.*;
import java.util.logging.Level;
import java.util.logging.Logger;

public class CustomerOrderController {

    //---------------------------------------------------------------- Customer ----------------------------------------------------------------
    @FXML
    public TableView<Dish> CustomerDishTableview;
    @FXML
    public TableColumn<Dish,String> CustomerDescriptionColumn;
    @FXML
    public TableColumn <Dish,String> CustomerNameColumn;
    @FXML
    public TableColumn<Dish,String> CustomerIngredientsColumn;
    @FXML
    public TableColumn<Dish,Integer> CustomerPriceColumn;
    @FXML
    public TableColumn<Dish, Image> CustomerImageColumn;
    @FXML
    public TableColumn<Dish,Void> OptionsColumn;

    public DatabaseConnector database = new DatabaseConnector();

    public SimpleOrderStrategy orderstrategy = new SimpleOrderStrategy();

    public CustomizedDishDecorator customizeDishDecorator = new CustomizedDishDecorator();
    @FXML
    public Tab OrderedDishsTab;
    @FXML
    public Tab OrderADishTab;

    @FXML
    public TableView<Dish> OrderedDishTableview;
    public TableColumn<Dish,String> ExtraIngredientsColumn;
    public TableColumn<Dish,Image> OrderedDishImageColumn;
    public TableColumn<Dish,Integer> OrderedDishPriceColumn;
    public TableColumn<Dish,String> OrderedDishIngredientsColumn;
    public TableColumn<Dish,String> OrderedDishDescriptionColumn;
    public TableColumn<Dish,String> OrderedDishNameColumn;

    @FXML
    public void initialize() {
        CustomerNameColumn.setCellValueFactory(new PropertyValueFactory<>("Name"));
        CustomerDescriptionColumn.setCellValueFactory(new PropertyValueFactory<>("Description"));
        CustomerIngredientsColumn.setCellValueFactory(new PropertyValueFactory<>("ingredients"));
        CustomerPriceColumn.setCellValueFactory(new PropertyValueFactory<>("price"));
        CustomerImageColumn.setCellValueFactory(new PropertyValueFactory<>("image"));


        CustomerImageColumn.setCellFactory(param -> new TableCell<>() {
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

        OptionsColumn.setCellFactory(param -> new TableCell<>() {
            private final Button customizeButton = new Button("Customize");
            private final Button orderButton = new Button("Order");

            {
                customizeButton.setOnAction(event -> handleCustomizeOrder());
                orderButton.setOnAction(event -> handleRegularOrder());

                // Add spacing between buttons
                customizeButton.setStyle("-fx-margin: 5;");

                // Set different colors to the buttons
                customizeButton.setStyle("-fx-background-color: #4CAF50; -fx-text-fill: white;");
                orderButton.setStyle("-fx-background-color: #008CBA; -fx-text-fill: white;");
            }

            @Override
            protected void updateItem(Void item, boolean empty) {
                super.updateItem(item, empty);

                if (empty) {
                    setGraphic(null);
                } else {
                    HBox buttonsContainer = new HBox(5, customizeButton, orderButton);
                    setGraphic(buttonsContainer);
                }
            }

            private void handleCustomizeOrder() {
                Dish selectedDish = getTableView().getItems().get(getIndex());
                if (selectedDish != null) {
                    // Create a GridPane for the dialog content
                    GridPane grid = new GridPane();
                    grid.setHgap(10);
                    grid.setVgap(10);

                    // Add labels and text fields for quantity and extras
                    grid.add(new Label("Quantity:"), 0, 0);
                    TextField quantityField = new TextField("1");
                    grid.add(quantityField, 1, 0);

                    // Add a new label and text field for extras
                    grid.add(new Label("Extras ingredients:"), 0, 1);
                    TextField extrasField = new TextField();
                    grid.add(extrasField, 1, 1);

                    // Create the TextInputDialog with the GridPane as the content
                    TextInputDialog dialog = new TextInputDialog();
                    dialog.setTitle("Customize Order");
                    dialog.setHeaderText(null);
                    dialog.setGraphic(grid);

                    // Deactivate the default TextField
                    dialog.getEditor().setVisible(false);

                    // Show the dialog and get the result
                    dialog.showAndWait().ifPresent(input -> {
                        try {
                            int quantity = Integer.parseInt(quantityField.getText().trim());
                            // Get extras from the user input
                            String extras = extrasField.getText();

                            customizeDishDecorator.customize(selectedDish, quantity, extras);
                        } catch (NumberFormatException e) {
                            // Handle invalid input
                            System.out.println("Invalid quantity entered");
                        }
                    });
                }
            }

            private void handleRegularOrder() {
                Dish selectedDish = getTableView().getItems().get(getIndex());
                if (selectedDish != null) {
                    // Prompt the user for the quantity
                    TextInputDialog dialog = new TextInputDialog("1");
                    dialog.setTitle("Order Quantity");
                    dialog.setHeaderText(null);
                    dialog.setContentText("Enter quantity:");

                    // Show the dialog and get the result
                    dialog.showAndWait().ifPresent(quantity -> {
                        try {
                            int orderQuantity = Integer.parseInt(quantity);
                            // Process the order with the selected quantity
                            orderstrategy.processOrder(selectedDish, orderQuantity);
                        } catch (NumberFormatException e) {
                            // Handle invalid input
                            System.out.println("Invalid quantity entered");
                        }
                    });
                }
            }
        });

        OrderedDishNameColumn.setCellValueFactory(new PropertyValueFactory<>("Name"));
        OrderedDishDescriptionColumn.setCellValueFactory(new PropertyValueFactory<>("Description"));
        OrderedDishIngredientsColumn.setCellValueFactory(new PropertyValueFactory<>("ingredients"));
        OrderedDishPriceColumn.setCellValueFactory(new PropertyValueFactory<>("price"));
        OrderedDishImageColumn.setCellValueFactory(new PropertyValueFactory<>("image"));
        ExtraIngredientsColumn.setCellValueFactory(new PropertyValueFactory<>("Extras"));


        OrderedDishImageColumn.setCellFactory(param -> new TableCell<>() {
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
        displayDishTable();

        OrderADishTab.setOnSelectionChanged(event -> {
            if (OrderADishTab.isSelected()) {
                // When the Deliveration tab is selected, display all pizzas
                displayDishTable();
            }
        });
        OrderedDishsTab.setOnSelectionChanged(event -> {
            if (OrderedDishsTab.isSelected()) {
                // When the Deliveration tab is selected, display all pizzas
                displayOrderedDishTable();
            }
        });

    }

    @FXML
    public void displayOrderedDishTable() {
        try {
            Connection conn = database.getConnection();
            String query = "SELECT * FROM pizza_db.dishOrdered_tb";

            try (PreparedStatement stmt = conn.prepareStatement(query);
                 ResultSet rs = stmt.executeQuery()) {

                ObservableList<Dish> dishList = FXCollections.observableArrayList();

                while (rs.next()) {
                    String dishName = rs.getString("name");
                    Integer number = rs.getInt("number");
                    Integer price = rs.getInt("price");
                    String extras = rs.getString("toppings");  // Use toppings column for extras

                    String query1 = "SELECT * FROM pizza_db.dish_tb WHERE name = ?";
                    try (PreparedStatement stmt1 = conn.prepareStatement(query1)) {
                        stmt1.setString(1, dishName);
                        try (ResultSet rs1 = stmt1.executeQuery()) {
                            if (rs1.next()) {
                                String ingredients = rs1.getString("ingredients");
                                String description = rs1.getString("description");
                                Blob imageBlob = rs1.getBlob("image");

                                Image image = null;

                                if (imageBlob != null) {
                                    try (InputStream inputStream = imageBlob.getBinaryStream()) {
                                        byte[] imageBytes = inputStream.readAllBytes();
                                        ByteArrayInputStream byteArrayInputStream = new ByteArrayInputStream(imageBytes);
                                        image = new Image(byteArrayInputStream);
                                    } catch (IOException e) {
                                        Logger.getLogger(CustomerOrderController.class.getName()).log(Level.SEVERE, null, e);
                                    }
                                }

                                Dish dish = new Dish(dishName, description, ingredients, price, image, extras);
                                dishList.add(dish);
                            }
                        }
                    } catch (SQLException e) {
                        Logger.getLogger(CustomerOrderController.class.getName()).log(Level.SEVERE, null, e);
                    }
                }

                OrderedDishTableview.setItems(dishList);
                OrderedDishTableview.refresh(); // Add this line to refresh the TableView
            }
        } catch (SQLException e) {
            Logger.getLogger(CustomerOrderController.class.getName()).log(Level.SEVERE, null, e);
        }
    }

    @FXML
    public void displayDishTable() {
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

                CustomerDishTableview.setItems(dishList);
                CustomerDishTableview.refresh(); // Add this line to refresh the TableView
            }
        } catch (SQLException e) {
            Logger.getLogger(DishOrderController.class.getName()).log(Level.SEVERE, null, e);
        }
    }

}
