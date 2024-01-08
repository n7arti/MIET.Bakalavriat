package org.example;

import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.support.FindBy;
import org.openqa.selenium.support.PageFactory;

public class FindPage {
    public WebDriver driver;
    public FindPage(WebDriver driver){
        PageFactory.initElements(driver, this);
        this.driver = driver;
    }
    @FindBy(xpath = "//*[contains(@name, 'query')]")
    private WebElement findField;
    @FindBy(xpath = "//*[contains(@value, 'Начать поиск')]")
    private WebElement findButton;

    public void inputFind(String find){
        findField.sendKeys(find);
    }

    public void clickfindButton(){
        findButton.click();
    }
}
