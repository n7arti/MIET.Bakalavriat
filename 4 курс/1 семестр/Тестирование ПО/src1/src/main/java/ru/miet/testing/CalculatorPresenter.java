package ru.miet.testing;

public interface CalculatorPresenter {
     /**
     * Вызывается формой в тот момент, когда пользователь нажал на кнопку '+'
     */
    public void onPlusClicked() throws Exception;

    /**
     * Вызывается формой в тот момент, когда пользователь нажал на кнопку '-'
     */
    public void onMinusClicked() throws Exception;

    /**
     * Вызывается формой в тот момент, когда пользователь нажал на кнопку '/'
     */
    public void onDivideClicked() throws Exception;

    /**
     * Вызывается формой в тот момент, когда пользователь нажал на кнопку '*'
     */
    public void onMultiplyClicked() throws Exception;
}
