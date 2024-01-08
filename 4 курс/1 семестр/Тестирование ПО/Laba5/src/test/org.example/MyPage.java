package org.example;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.support.FindBy;
import org.openqa.selenium.support.PageFactory;


public class MyPage {
    public WebDriver driver;
    public MyPage(WebDriver driver){
        PageFactory.initElements(driver, this);
        this.driver = driver;
    }
    private WebElement like;
    private WebElement loginButton;
    private WebElement loginButton2;
    private WebElement button;
    private WebElement emailField;
    private WebElement passwordField;
    public String getlike(){
        return driver.findElement(By.xpath("//*[@id=\"post160806013_3307\"]/div/div[2]/div/div[2]/div/div[1]/div[1]/div[1]/span[3]/div")).getText();
    }
    public void clickLike(){
        like = driver.findElement(By.xpath("//*[@id=\"post160806013_3307\"]/div/div[2]/div/div[2]/div/div[1]/div[1]"));
        like.click();
    }
    public void clickLogin(){
        loginButton = driver.findElement(By.xpath("//*[text()='Войти']"));
        loginButton.click();
    }
    public void clickLogin2(){
        loginButton2 = driver.findElement(By.xpath("//*[@id=\"content\"]/div[1]/form/button[1]/span"));
        loginButton2.click();
    }
    public void click(){
        button = driver.findElement(By.xpath("//*[text()='Продолжить']"));
        button.click();
    }
    public void inputLogin(String email){
        emailField = driver.findElement(By.id("index_email"));
        emailField.sendKeys(email);
    }

    public void inputPassword(String password){
        passwordField = driver.findElement(By.xpath("//*[@id=\"root\"]/div/div/div/div/div[2]/div/div/div/form/div[1]/div[3]/div[1]/div/input"));
        passwordField.sendKeys(password);
    }
}