package org.example;

import org.junit.AfterClass;
import org.junit.Assert;
import org.junit.BeforeClass;
import org.junit.Test;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.chrome.ChromeDriver;

import java.util.concurrent.TimeUnit;

public class FindTest {
    public static FindPage findPage;
    public static ResultPage resultPage;
    public static WebDriver driver;

    @BeforeClass
    public static void setup() {
        System.setProperty("webdriver.chrome.driver", "C:\\Users\\nastena\\Downloads\\chromedriver_win32\\chromedriver.exe");
        driver = new ChromeDriver();
        findPage = new FindPage(driver);
        resultPage = new ResultPage(driver);
        driver.manage().window().maximize();
        driver.manage().timeouts().implicitlyWait(10, TimeUnit.SECONDS);
        driver.get("https://www.cyberforum.ru/search.php?do=process");
    }
    /**
     * тестовый метод для осуществления аутентификации
     */
    @Test
    public void findTest() {
        String find = "selenium";
        findPage.inputFind(find);
        findPage.clickfindButton();
        String error = resultPage.getError();
        Assert.assertEquals("Вам необходимо пройти проверку перед завершением регистрации.", error); }
    /**
     * осуществление выхода из аккаунта с последующим закрытием окна браузера
     */
    @AfterClass
    public static void tearDown() {
        driver.quit();
    }
}
