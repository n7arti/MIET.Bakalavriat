package org.example;

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
    @FindBy(xpath = "/html/body/div/div[1]/div/div/table[1]/tbody/tr/td[2]/div/span[1]/b/a")
    private WebElement userName;
    @FindBy(xpath = "//*[contains(text(), 'Выход')]")
    private WebElement exitButton;
    public String getUserName(){
        return userName.getText();
    }
    public void clicExitButton(){
        exitButton.click();
    }
}
