package com.example.onlinefood;

import javafx.css.Size;
import javafx.scene.image.Image;

import java.util.List;

public interface DishFactory {
    Dish createDish(String name, Integer price, String ingredients, String description, Image image);
    void deleteDish(Dish dish);
    void editDish(Dish dish);
}

