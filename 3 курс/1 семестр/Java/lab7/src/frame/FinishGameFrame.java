package frame;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowEvent;
import java.util.ArrayList;

public class FinishGameFrame extends JFrame implements ActionListener {
    private JPanel panel;
    private GridBagConstraints gbc;
    private JButton restart;
    private JLabel win;
    public FinishGameFrame(String textWin) {
        setSize(15*20 , 11*20);
        GridBagLayout layout = new GridBagLayout();
        gbc = new GridBagConstraints();

        panel = new JPanel();
        panel.setLayout(layout);
        panel.setBackground(Color.white);
        getRootPane().setBorder(BorderFactory.createMatteBorder(1, 1, 1, 1, Color.BLACK));


        restart = new JButton("RESTART");
        gbc.gridx = 0;
        gbc.gridy = 1;
        gbc.weightx = 1;
        gbc.weighty = 0.5;
        gbc.gridheight = 1;
        gbc.gridwidth = 1;
        gbc.anchor = GridBagConstraints.CENTER;
        restart.setActionCommand("restart");
        restart.addActionListener(this);
        panel.add(restart,gbc);

        win = new JLabel(textWin);
        win.setHorizontalAlignment(JLabel.CENTER);
        gbc.fill = GridBagConstraints.VERTICAL;
        //gbc.weighty = 0.98;
        gbc.gridy = 0;
        gbc.anchor = GridBagConstraints.CENTER;
        panel.add(win,gbc);
        getContentPane().add(panel);
    }


    @Override
    public void actionPerformed(ActionEvent e) {
        this.dispatchEvent(new WindowEvent(this, WindowEvent.WINDOW_CLOSING));
    }
}
