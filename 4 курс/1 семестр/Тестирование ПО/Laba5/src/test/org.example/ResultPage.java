package org.example;

import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.support.FindBy;
import org.openqa.selenium.support.PageFactory;

public class ResultPage {
    public WebDriver driver;
    public ResultPage(WebDriver driver){
        PageFactory.initElements(driver, this);
        this.driver = driver;
    }
    @FindBy(xpath = "/html/body/div[1]/div[1]/div/div/table[3]/tbody/tr[2]/td/ol/li")
    private WebElement error;

    public String getError(){
        return error.getText();
    }
}
