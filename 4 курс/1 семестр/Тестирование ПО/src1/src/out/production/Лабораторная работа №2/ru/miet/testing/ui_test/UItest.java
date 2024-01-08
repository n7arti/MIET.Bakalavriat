package ui_test;

import org.junit.jupiter.api.Test;
import ru.miet.testing.Interface;

import javax.swing.*;
import java.awt.*;
import java.awt.event.InputEvent;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class UItest {
    String error1 = "Аргументы не должны быть пустыми";
    String error2 = "Аргументы должны быть числом";
    String error3 = "На ноль делить нельзя";
    MyMock interf = new MyMock();
    public void click(JButton button, Robot robot) throws InterruptedException {
        Point p = button.getLocation();
        robot.mouseMove(p.x,p.y);
        robot.mousePress(InputEvent.BUTTON1_DOWN_MASK);
        Thread.sleep(10);
        robot.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
        Thread.sleep(3000);
    }

    @Test
    public void nullNumbers(){
        interf.error = null;
        try{
            Robot robot = new Robot();
            Thread.sleep(1000);
            click(interf.plusButton,robot);

        } catch (AWTException ex){
            ex.printStackTrace();
        }
        catch (Exception ex) {
            interf.error = ex.getMessage();
        }
        assertEquals(error1, interf.error);
    }

    @Test
    public void letter(){
        interf.error = null;
        try{
            Robot robot = new Robot();
            interf.ANumInputField.setText("a");
            Thread.sleep(1000);
            interf.BNumInputField.setText("b");
            Thread.sleep(1000);
            click(interf.plusButton,robot);
        }catch (AWTException ex){
            ex.printStackTrace();
        }
        catch (Exception ex) {
            interf.error = ex.getMessage();
        }
        assertEquals(error2, interf.error);
    }

    @Test
    public void zerodivide(){
        Interface.error = null;
        try{
            Robot robot = new Robot();
            interf.ANumInputField.setText("10");
            Thread.sleep(1000);
            interf.BNumInputField.setText("0");
            Thread.sleep(1000);
            click(interf.plusButton,robot);
        }catch (AWTException ex){
            ex.printStackTrace();
        }
        catch (Exception ex) {
            interf.error = ex.getMessage();
        }
        assertEquals(error3, interf.error);
    }

    @Test
    public void plus(){
        Interface.error = null;
        try{
            Robot robot = new Robot();
            interf.ANumInputField.setText("10");
            Thread.sleep(1000);
            interf.BNumInputField.setText("10");
            Thread.sleep(1000);
            click(interf.plusButton,robot);
        }catch (AWTException ex){
            ex.printStackTrace();
        }
        catch (Exception ex) {
            interf.error = ex.getMessage();
        }
        assertEquals("20", interf.ResultInputField.getText());
    }

    @Test
    public void subtract(){
        Interface.error = null;
        try{
            Robot robot = new Robot();
            interf.ANumInputField.setText("10");
            Thread.sleep(1000);
            interf.BNumInputField.setText("10");
            Thread.sleep(1000);
            click(interf.subtractButton,robot);
        }catch (AWTException ex){
            ex.printStackTrace();
        }
        catch (Exception ex) {
            interf.error = ex.getMessage();
        }
        assertEquals("0", interf.ResultInputField.getText());
    }

    @Test
    public void multiply(){
        Interface.error = null;
        try{
            Robot robot = new Robot();
            interf.ANumInputField.setText("10");
            Thread.sleep(1000);
            interf.BNumInputField.setText("10");
            Thread.sleep(1000);
            click(interf.multiplyButton,robot);
        }catch (AWTException ex){
            ex.printStackTrace();
        }
        catch (Exception ex) {
            interf.error = ex.getMessage();
        }
        assertEquals("100", interf.ResultInputField.getText());
    }

    @Test
    public void divide(){
        Interface.error = null;
        try{
            Robot robot = new Robot();
            interf.ANumInputField.setText("10");
            Thread.sleep(1000);
            interf.BNumInputField.setText("10");
            Thread.sleep(1000);
            click(interf.divideButton,robot);
        }catch (AWTException ex){
            ex.printStackTrace();
        }
        catch (Exception ex) {
            interf.error = ex.getMessage();
        }
        assertEquals("1", interf.ResultInputField.getText());
    }
}
