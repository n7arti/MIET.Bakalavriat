package org.example;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.support.PageFactory;

public class MailPage {
    public WebDriver driver;
    public MailPage(WebDriver driver){
        PageFactory.initElements(driver, this);
        this.driver = driver;
    }

    private WebElement sendToField;
    private WebElement titleField;
    private WebElement writeButton;
    private WebElement sendButton;
    private WebElement refreshButton;
    public void inputTitle(String find){
        titleField = driver.findElement(By.name("subject"));
        titleField.sendKeys(find);
    }
    public String getTitle(){
        titleField = driver.findElement(By.xpath("//*[@id=\"js-apps-container\"]/div[2]/div[7]/div/div[3]/div[1]/div[2]/div/main/div[7]/div[1]/div/div/div[3]/div/div[1]/div/div/div/a/div/span[2]/div/span/span[1]/span[1]/span"));
        return titleField.getText();
    }
    public void inputSendTo(String find){
        sendToField = driver.findElement(By.xpath("//*[@id=\"compose-field-1\"]"));
        sendToField.sendKeys(find);
    }
    public void clickWriteButton(){
        writeButton = driver.findElement(By.xpath("//*[@id=\"js-apps-container\"]/div[2]/div[7]/div/div[3]/div[1]/nav/div[2]/div/div/div/a"));
        writeButton.click();
    }
    public void clickSendButton(){
        sendButton = driver.findElement(By.xpath("//*[@id=\"js-apps-container\"]/div[2]/div[10]/div/div/div[1]/div/div/div/div[1]/div[1]/div[2]/div/div[1]/div[1]/button"));
        sendButton.click();
    }
    public void clickRefreshButton(){
        refreshButton = driver.findElement(By.xpath("//*[@id=\"js-apps-container\"]/div[2]/div[7]/div/div[3]/div[1]/nav/div[2]/div/div/div/button"));
        refreshButton.click();
    }
}
