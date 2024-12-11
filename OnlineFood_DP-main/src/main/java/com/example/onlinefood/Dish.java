package com.example.onlinefood;
import javafx.scene.image.Image;
import java.util.List;

public class Dish {
    private String name;
    private String description;
    private String ingredients;
    private Integer price;
    private Image image;
    private String extras;


    Dish(String name, String description, String ingredients, Integer price, Image image, String extras){
        this.name = name;
        this.description = description;
        this.ingredients = ingredients;
        this.price = price;
        this.image = image;
        this.extras = extras;
    }

    Dish(String name, String description, String ingredients, Integer price, Image image){
        this.name = name;
        this.description = description;
        this.ingredients = ingredients;
        this.price = price;
        this.image = image;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public String getIngredients() {
        return ingredients;
    }

    public void setIngredients(String ingredients) {
        this.ingredients = ingredients;
    }

    public Integer getPrice() {
        return price;
    }

    public void setPrice(Integer price) {
        this.price = price;
    }



    public Image getImage() {
        return image;
    }

    public void setImage(Image image) {
        this.image = image;
    }

    public String getExtras() {
        return extras;
    }

    public void setExtras(String extras) {
        this.extras = extras;
    }
}

