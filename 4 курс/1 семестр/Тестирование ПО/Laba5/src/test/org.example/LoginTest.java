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
        //окно разворачивается на полный экран
        driver.manage().window().maximize();
        //задержка на выполнение теста = 10 сек.
        driver.manage().timeouts().implicitlyWait(10, TimeUnit.SECONDS);
        //получение ссылки на страницу входа из файла настроек
        driver.get("https://www.cyberforum.ru/auth.php");
    }
    /**
     * тестовый метод для осуществления аутентификации
     */
    @Test
    public void loginTest() {
        //получение доступа к методам класса LoginPage для взаимодействия с элементами страницы
        //значение login/password берутся из файла настроек по аналогии с chromedriver
        //и loginpage
        //вводим логин
        //region логин, пароль
        String email = "n7arti@mail.ru";
        String password = "NA757150";
        //endregion
        loginPage.inputLogin(email);
        //вводим пароль
        loginPage.inputPassword(password);
        //нажимаем кнопку входа
        loginPage.clickLoginButton();
        //получаем отображаемый логин
        String user  = profilePage.getUserName();
        //и сравниваем его с логином из файла настроек
        Assert.assertEquals("n7arti", user); }
    /**
     * осуществление выхода из аккаунта с последующим закрытием окна браузера
     */
    @AfterClass
    public static void tearDown() {
        profilePage.clicExitButton();
        driver.quit();
    }
}

