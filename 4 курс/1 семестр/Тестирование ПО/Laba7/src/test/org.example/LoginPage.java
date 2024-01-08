package org.example;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.support.FindBy;
import org.openqa.selenium.support.PageFactory;

public class LoginPage {
    public WebDriver driver;
    public LoginPage(WebDriver driver){
        PageFactory.initElements(driver, this);
        this.driver = driver;
    }

    private WebElement emailField;
    private WebElement passwordField;

    private WebElement loginButton;
    private WebElement emailButton;
    private WebElement confirmButton;
    public void inputLogin(String email){
        emailField = driver.findElement(By.name("login"));
        emailField.sendKeys(email);
    }
    public void inputPassword(String password){
        passwordField = driver.findElement(By.name("passwd"));
        passwordField.sendKeys(password);
    }

    public void clickLoginButton(){
        loginButton = driver.findElement(By.id("passp:sign-in"));
        loginButton.click();
    }

    public void clickEmailButton(){
        emailButton = driver.findElement(By.xpath("//*[@id=\"root\"]/div/div[2]/div[2]/div/div/div[2]/div[3]/div/div/div/div[1]/form/div[1]/div[1]/button"));
        emailButton.click();
    }
    public void clickConfirmButton(){
        confirmButton = driver.findElement(By.xpath("//*[@id=\"root\"]/div/div[2]/div[2]/div/div/div[2]/div[3]/div/div/div/div[1]/form/div[2]/button"));
        confirmButton.click();
    }
}