package main;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.TimeUnit;

import org.junit.AfterClass;
import org.junit.BeforeClass;
import org.junit.Test;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.chrome.ChromeDriver;

public class ScheduleParser {
    public static SchedulePage schedulePage;
    public static WebDriver driver;

    @BeforeClass
    public static void setup() {
        //определение пути до драйвера и его настройка
        System.setProperty("webdriver.chrome.driver", "C:\\Users\\nastena\\Downloads\\chromedriver_win32\\chromedriver.exe");
        //создание экземпляра драйвера
        driver = new ChromeDriver();
        schedulePage = new SchedulePage(driver);
        //окно разворачивается на полный экран
        driver.manage().window().maximize();
        //задержка на выполнение теста = 10 сек.
        driver.manage().timeouts().implicitlyWait(10, TimeUnit.SECONDS);
        driver.get("https://www.miet.ru/schedule");
    }
    /**
     * тестовый метод для осуществления аутентификации
     */
    @Test
    public void loginTest() throws InterruptedException {
        List<WebElement> grouplist;
        List<Group> groups = new ArrayList<>();

        grouplist = schedulePage.getGroups();
        Thread.sleep(100);
        for(int i=1;i<grouplist.size();i++) {
            schedulePage.inputGroup(grouplist.get(i).getText());
            Thread.sleep(100);
            groups.add(new Group(grouplist.get(i).getText(),schedulePage.getShedule()));
            Thread.sleep(100);
        }
        JSONFile.inFile(groups);
    }
    /**
     * осуществление выхода из аккаунта с последующим закрытием окна браузера
     */
    @AfterClass
    public static void tearDown() {
        driver.quit();
    }
}
