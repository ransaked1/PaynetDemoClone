package com.example.paynetdemo.ui.LoyaltyFragments;

public class Card {

    private String Title;
    private int Image;

    public Card() {
    }

    public Card(String title, int image) {
        Title = title;
        Image = image;
    }

    public String getTitle() {
        return Title;
    }

    public int getImage() {
        return Image;
    }

    public void setTitle(String title) {
        Title = title;
    }

    public void setImage(int image) {
        Image = image;
    }
}
