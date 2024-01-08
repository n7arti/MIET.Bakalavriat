package org.example;

import org.junit.AfterClass;
import org.junit.Assert;
import org.junit.BeforeClass;
import org.junit.Test;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.chrome.ChromeDriver;

import java.util.concurrent.TimeUnit;

public class RatingTest {
    public static MyPage postsPage;
    public static WebDriver driver;

    @BeforeClass
    public static void setup() {
        System.setProperty("webdriver.chrome.driver", "C:\\Users\\nastena\\Downloads\\chromedriver_win32\\chromedriver.exe");
        driver = new ChromeDriver();
        postsPage = new MyPage(driver);
        driver.manage().window().maximize();
        driver.manage().timeouts().implicitlyWait(10, TimeUnit.SECONDS);
        driver.get("https://vk.com/n7arti");
    }

    @Test
    public void ratingTest() throws InterruptedException {
        //region логин, пароль
        String email = "89209089377";
        String password = "n7art757150";
        //endregion
        postsPage.clickLogin();
        Thread.sleep(1000);
        postsPage.inputLogin(email);
        postsPage.clickLogin2();
        postsPage.inputPassword(password);
        postsPage.click();
        Thread.sleep(1000);
        String likebefore = postsPage.getlike();
        postsPage.clickLike();
        Thread.sleep(2000);
        String likeafter =Integer.toString(Integer.parseInt(postsPage.getlike()) -1);
        postsPage.clickLike();
        Assert.assertEquals(likebefore, likeafter);
    }

    @AfterClass
    public static void tearDown() {
        driver.quit();
    }
}
