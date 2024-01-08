package ru.miet.testing;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class CalcControllerTest {

    @Test
    void onPlusClicked() throws Exception {
        CalcView calcView = new CalcView();
        CalcController calcController = new CalcController();
        calcController.calcView = calcView;
        calcController.onPlusClicked();
    }

    @Test
    void onMinusClicked() {
    }

    @Test
    void onMultiplyClicked() {
    }

    @Test
    void onDivideClicked() {
    }
}