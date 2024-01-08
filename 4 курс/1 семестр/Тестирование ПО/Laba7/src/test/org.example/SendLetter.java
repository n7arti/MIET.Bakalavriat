package org.example;

import org.junit.AfterClass;
import org.junit.Assert;
import org.junit.BeforeClass;
import org.junit.Test;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.chrome.ChromeDriver;

import java.util.concurrent.TimeUnit;

public class SendLetter {
    public static MailPage mailPage;
    public static LoginPage loginPage;
    public static ProfilePage profilePage;
    public static WebDriver driver;

    @BeforeClass
    public static void setup() {
        System.setProperty("webdriver.chrome.driver", "C:\\Users\\nastena\\Downloads\\chromedriver_win32\\chromedriver.exe");
        driver = new ChromeDriver();
        loginPage = new LoginPage(driver);
        profilePage = new ProfilePage(driver);
        mailPage = new MailPage(driver);
        driver.manage().window().maximize();
        driver.manage().timeouts().implicitlyWait(10, TimeUnit.SECONDS);
        driver.get("https://passport.yandex.ru/auth");
    }
    /**
     * тестовый метод для осуществления аутентификации
     */
    @Test
    public void sendTest() throws InterruptedException {
        //region логин, пароль
        String email = "K1SELKA@yandex.ru";
        String password = "1qa@WS3ed1234";
        //endregion
        loginPage.clickEmailButton();
        loginPage.inputLogin(email);
        loginPage.clickLoginButton();
        loginPage.inputPassword(password);
        loginPage.clickLoginButton();
        loginPage.clickConfirmButton();
        Thread.sleep(20000);
        driver.get("https://mail.yandex.ru/");
        mailPage.clickWriteButton();
        mailPage.inputSendTo(email);
        mailPage.inputTitle("text");
        mailPage.clickSendButton();
        Thread.sleep(5000);
        mailPage.clickRefreshButton();
        driver.get("https://mail.yandex.ru/");
        Thread.sleep(1000);
        String title = mailPage.getTitle();
        Assert.assertEquals("text", title);
    }
    /**
     * осуществление выхода из аккаунта с последующим закрытием окна браузера
     */
    @AfterClass
    public static void tearDown() {
        driver.quit();
    }
}
