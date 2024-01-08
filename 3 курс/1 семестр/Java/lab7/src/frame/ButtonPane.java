package frame;

import javax.swing.*;
import java.awt.*;

public class ButtonPane extends JButton {
    public ButtonPane(Color color){
        setBackground(color);
        setSize(100,50);
        setBorder(BorderFactory.createMatteBorder(2, 2, 2, 2, Color.WHITE));
    }
    public void run(int speed){
        Rectangle bounds = getBounds();
        bounds.x +=speed;
        setBounds(bounds);
    }
}
