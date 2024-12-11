package com.example.onlinefood;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.stage.Stage;

public class ChoiceController {
    @FXML
    private Button AdminButton;
    @FXML
    private Button CustomerButton;

    public void handleAdminButtonClick(ActionEvent event) throws Exception {
        loadFXML("Admin.fxml");
    }

    public void handleCustomerButtonClick(ActionEvent event) throws Exception {
        loadFXML("Customer.fxml");
    }

    private void loadFXML(String fxmlFileName) throws Exception {
        FXMLLoader loader = new FXMLLoader(getClass().getResource(fxmlFileName));
        Parent root = loader.load();

        Stage stage = new Stage();
        stage.setScene(new Scene(root));
        stage.show();
    }
}
