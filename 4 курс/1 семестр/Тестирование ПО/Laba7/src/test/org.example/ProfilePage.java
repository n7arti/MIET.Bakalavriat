package org.example;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.support.FindBy;
import org.openqa.selenium.support.PageFactory;

public class ProfilePage {
    public WebDriver driver;
    public ProfilePage(WebDriver driver){
        PageFactory.initElements(driver, this);
        this.driver = driver;
    }

    private WebElement userName;
    private WebElement dataButton;
    private WebElement profileButton;
    private WebElement emailButton;
    public String getUserName(){
        userName = driver.findElement(By.xpath("//*[@id=\"__next\"]/div/main/div/div[1]/div/div/div[2]/span"));
        return userName.getText();
    }
    public void clickDataButton(){
        dataButton = driver.findElement(By.xpath("//*[@id=\"__next\"]/div/div/nav/ul/li[2]/a"));
        dataButton.click();
    }
    public void clickProfileButton(){
        profileButton = driver.findElement(By.xpath("//*[@id=\"__next\"]/div/header/div[4]/div/div[1]/a[1]"));
        profileButton.click();
    }

    public void clickEmailButton(){
        emailButton = driver.findElement(By.xpath("//*[contains(text(), 'Почта')]"));
                //driver.findElement(By.xpath("//*[@id=\"root\"]/div/div/div/div[2]/a[1]"));
        emailButton.click();
    }
}
