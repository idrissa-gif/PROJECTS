package com.example.onlinefood;

import javafx.scene.control.Alert;

public interface OrderStrategy {
    void processOrder(Dish order,Integer number);
}
