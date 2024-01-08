package org.example;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.support.PageFactory;

import java.util.List;


public class LetterPage {
    public WebDriver driver;
    public LetterPage(WebDriver driver){
        PageFactory.initElements(driver, this);
        this.driver = driver;
    }
    private List<WebElement> titles;
    private WebElement loginButton;
    private WebElement loginButton2;
    private WebElement button;
    private WebElement emailField;
    private WebElement passwordField;
    public void clickLetters(){
        titles = driver.findElements(By.xpath("span[contains(text(),'text1')]"));
        for (WebElement title: titles) {
            title.click();
        }
    }

}