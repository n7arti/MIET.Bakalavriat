package org.example;

import org.junit.AfterClass;
import org.junit.Assert;
import org.junit.BeforeClass;
import org.junit.Test;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.chrome.ChromeDriver;

import java.util.concurrent.TimeUnit;

public class LoginTest {
    public static LoginPage loginPage;
    public static ProfilePage profilePage;
    public static WebDriver driver;

    @BeforeClass
    public static void setup() {
        //определение пути до драйвера и его настройка
        System.setProperty("webdriver.chrome.driver", "C:\\Users\\nastena\\Downloads\\chromedriver_win32\\chromedriver.exe");
        //создание экземпляра драйвера
        driver = new ChromeDriver();
        loginPage = new LoginPage(driver);
        profilePage = new ProfilePage(driver);
        profilePage = new ProfilePage(driver);
        //окно разворачивается на полный экран
        driver.manage().window().maximize();
        //задержка на выполнение теста = 10 сек.
        driver.manage().timeouts().implicitlyWait(10, TimeUnit.SECONDS);
        //получение ссылки на страницу входа из файла настроек
        driver.get("https://passport.yandex.ru/auth");
    }
    /**
     * тестовый метод для осуществления аутентификации
     */
    @Test
    public void loginTest() throws InterruptedException {
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
        profilePage.clickDataButton();
        String user  = profilePage.getUserName();
        Assert.assertEquals("Влад Киселёв", user);
    }
    /**
     * осуществление выхода из аккаунта с последующим закрытием окна браузера
     */
    @AfterClass
    public static void tearDown() {
        driver.quit();
    }
}

