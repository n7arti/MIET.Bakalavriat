package org.example;

import org.junit.AfterClass;
import org.junit.Assert;
import org.junit.BeforeClass;
import org.junit.Test;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.chrome.ChromeDriver;

import java.util.concurrent.TimeUnit;

public class DeleteLetter {
    public static LetterPage letterPage;
    public static LoginPage loginPage;
    public static ProfilePage profilePage;
    public static WebDriver driver;

    @BeforeClass
    public static void setup() {
        System.setProperty("webdriver.chrome.driver", "C:\\Users\\nastena\\Downloads\\chromedriver_win32\\chromedriver.exe");
        driver = new ChromeDriver();
        loginPage = new LoginPage(driver);
        letterPage = new LetterPage(driver);
        driver.manage().window().maximize();
        driver.manage().timeouts().implicitlyWait(10, TimeUnit.SECONDS);
        driver.get("https://passport.yandex.ru/auth");
    }

    @Test
    public void deleteTest() throws InterruptedException {
        //region логин, пароль
        String email = "K1SELKA@yandex.ru";
        String password = "1qa@WS3ed1234";
        //endregion
        loginPage.clickEmailButton();
        loginPage.inputLogin(email);
        loginPage.clickLoginButton();
        loginPage.inputPassword(password);
        loginPage.clickLoginButton();
        Thread.sleep(1000);
        loginPage.clickConfirmButton();
        Thread.sleep(20000);
        driver.get("https://mail.yandex.ru/");
        Thread.sleep(1000);
        letterPage.clickLetters();
        //Assert.assertEquals(likebefore, likeafter);
        //span[contains(text(),'11A-7E2-V0005')]
    }

    @AfterClass
    public static void tearDown() {
        driver.quit();
    }
}
