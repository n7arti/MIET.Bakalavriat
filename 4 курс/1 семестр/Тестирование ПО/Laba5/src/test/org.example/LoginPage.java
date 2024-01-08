package org.example;

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
    @FindBy(xpath = "//*[contains(@name, 'vb_login_username')]")
    private WebElement emailField;
    @FindBy(xpath = "//*[contains(@name, 'vb_login_password')]")
    private WebElement passwordField;
    @FindBy(xpath = "//*[contains(@value, 'Вход')]")
    private WebElement loginButton;

    public void inputLogin(String email){
        emailField.sendKeys(email);
    }

    public void inputPassword(String password){
        passwordField.sendKeys(password);
    }

    public void clickLoginButton(){
        loginButton.click();
    }
}