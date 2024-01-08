package main;

import org.openqa.selenium.By;
import org.openqa.selenium.JavascriptExecutor;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.support.PageFactory;
import org.openqa.selenium.support.ui.Select;

import java.util.Iterator;
import java.util.List;

public class SchedulePage {
    public WebDriver driver;

    public SchedulePage(WebDriver driver) {
        PageFactory.initElements(driver, this);
        this.driver = driver;
    }

    private Select dropdownlist;
    private List<WebElement> grouplist;
    private List<WebElement> schedule;
    private List<WebElement> scheduleInfo;
    private WebElement cl;

    public void inputGroup(String group) {
        dropdownlist = new Select(driver.findElement(By.className("group")));
        dropdownlist.selectByVisibleText(group);
    }

    public List<WebElement> getGroups() {
        grouplist = driver.findElements(By.tagName("option"));
        return grouplist;
//        for (WebElement group:grouplist) {
//            System.out.println(group.getText());
//        }
    }

    public Schedule getShedule() {
        Schedule scheduleGroup;
        cl = driver.findElement(By.xpath("/html/body/main/div[2]/div[2]/div[2]/table/tbody/tr[1]/th[1]/div"));
        Week[] week = new Week[4];
        Day[][] days = new Day[4][6];
        for (int i = 3; i < 9; i++) {
            Lesson[][] lesson = new Lesson[4][7];
            for (int j = 1; j < 8; j++) {
                schedule = driver.findElements(By.cssSelector("tbody tr:nth-child(" + j + ") td:nth-child(" + i + ") div.cell div.text"));
                for (int k = 0; k < schedule.size(); k++) {
                    //System.out.println("a " + schedule.get(k).getText());
                    schedule.get(k).click();
                    scheduleInfo = driver.findElements(By.cssSelector("tbody tr:nth-child(" + j + ") td:nth-child(" + i + ") div.cell div.info"));
                    //System.out.println("b " + scheduleInfo.get(k).getText());
                    String[] les = scheduleInfo.get(k).getText().split("\n");
                    if (les.length > 1) {
                        les[3] = les[3].split(":")[1];
                        les[4] = les[4].split(":")[1];
                        les[5] = les[5].split(":")[1];
                        switch (schedule.size()) {
                            case 1:
                                for (int z = 0; z < 4; z++)
                                    lesson[z][j - 1] = new Lesson(les[3], les[4], les[5]);
                                break;
                            case 2:
                                lesson[k * 2][j - 1] = new Lesson(les[3], les[4], les[5]);
                                lesson[k * 2 + 1][j - 1] = new Lesson(les[3], les[4], les[5]);
                                break;
                            case 3:
                                if (schedule.get(k).getText().substring(0, 2).equals("Ч-"))
                                    if (k == 2) {
                                        lesson[k][j - 1] = new Lesson(les[3], les[4], les[5]);
                                        lesson[k + 1][j - 1] = new Lesson(les[3], les[4], les[5]);
                                    } else
                                        lesson[k][j - 1] = new Lesson(les[3], les[4], les[5]);
                                else {
                                    if (k > 0) {
                                        lesson[k + 1][j - 1] = new Lesson(les[3], les[4], les[5]);
                                    } else {
                                        lesson[k][j - 1] = new Lesson(les[3], les[4], les[5]);
                                        lesson[k + 1][j - 1] = new Lesson(les[3], les[4], les[5]);
                                    }
                                }
                                break;
                            case 4:
                                lesson[k][j - 1] = new Lesson(les[3], les[4], les[5]);
                                break;
                        }
                    }
                    cl.click();
                }
            }
            for (int k = 0; k < 4; k++)
                days[k][i - 3] = new Day(lesson[k][0], lesson[k][1], lesson[k][2], lesson[k][3], lesson[k][4], lesson[k][5], lesson[k][6]);
        }
        for (int k = 0; k < 4; k++)
            week[k] = new Week(days[k][0], days[k][1], days[k][2], days[k][3], days[k][4], days[k][5]);
        scheduleGroup = new Schedule(week[0], week[1], week[2], week[3]);
        return scheduleGroup;
    }
}
