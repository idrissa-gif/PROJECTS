package com.example.lbms;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.stage.StageStyle;
//password = admin
import java.io.IOException;

public class Main extends Application {
    static public String Passwd , user;
    @Override
    public void start(Stage primaryStage) throws IOException {
        Parent root;
        root = FXMLLoader.load(getClass().getResource("Login.fxml"));
        Scene scene = new Scene(root);
        primaryStage.setScene(scene);
        primaryStage.show();
    }
    public static void main(String[] args) {
        launch(args);
    }
}
