import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.sql.*;

public class UI extends JDialog {
    private JPanel contentPane;
    private JButton buttonConnect;
    private JTextField ServerField;
    private JTextField PortField;
    private JTextField UserNameField;
    private JTextField PassField;
    private JTextField DBField;
    private JTextArea ParseProd;
    private JTextField descfield;
    private JTextField namefield;
    private JButton AddProd;
    private JButton RemoveProd;
    private JComboBox IDprod;
    private JTextField pricefield;
    private JButton FilterProd;
    private JTextField minprice;
    private JButton resetprod;
    private JButton UpdateBtn;
    private JTextField NameField2;
    private JTextField DescField2;
    private JTextField PriceField2;
    private JComboBox IDupd;

    public static class con {
        static Connection connection = null;
    }

    public UI() {
        setContentPane(contentPane);
        setModal(true);
        getRootPane().setDefaultButton(buttonConnect);
        this.setTitle("Java - PostgreSQL editor");
        this.setSize(1280, 720);
        this.setResizable(false);
        buttonConnect.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                onConnect();
            }
        });

        
        AddProd.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                AddItemProd();
            }
        });

        UpdateBtn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                Update();
            }
        });


        RemoveProd.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                RemoveItemProd();
            }
        });


        FilterProd.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                Filter_Prod();
            }
        });

        resetprod.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                GetTableProduct(false, 0);
                minprice.setText("");
            }
        });

        setDefaultCloseOperation(DO_NOTHING_ON_CLOSE);
        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                dispose();
            }
        });

    }

    public void enable_all(){
        AddProd.setEnabled(true);
        RemoveProd.setEnabled(true);
        IDprod.setEnabled(true);
        IDupd.setEnabled(true);
        ParseProd.setEnabled(true);
        namefield.setEnabled(true);
        descfield.setEnabled(true);
        pricefield.setEnabled(true);
        FilterProd.setEnabled(true);
        minprice.setEnabled(true);
        resetprod.setEnabled(true);
        NameField2.setEnabled(true);
        DescField2.setEnabled(true);
        PriceField2.setEnabled(true);
        UpdateBtn.setEnabled(true);
    }


    public void get_ids_prod(Statement statement, ResultSet result){
        try {
            statement = con.connection.createStatement();
            IDprod.removeAllItems();
            IDupd.removeAllItems();
            while(result.next()) {
                IDprod.addItem(result.getString("id"));
                IDupd.addItem(result.getString("id"));
            }
            statement.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private void onConnect() {
        //  Database credentials
        while (true) {
            final String URL = "jdbc:postgresql://";
            final String DB = DBField.getText();
            final String DB_URL = URL + ServerField.getText() + '/' + DB;
            final String USER = UserNameField.getText();
            final String PASS = PassField.getText();
            this.setTitle("Проверка подключения к PostgreSQL JDBC...");


            try {
                Class.forName("org.postgresql.Driver");
            } catch (ClassNotFoundException e) {
                this.setTitle("PostgreSQL JDBC Driver не найден.");
                e.printStackTrace();
                return;
            }

            this.setTitle("PostgreSQL JDBC Driver подключен");


            try {
                con.connection = DriverManager
                        .getConnection(DB_URL, USER, PASS);

            } catch (SQLException e) {
                JOptionPane.showMessageDialog(this, "Подключение не было произведено!",
                        "Ошибка подключения!", JOptionPane.ERROR_MESSAGE);
                System.out.println(e.getMessage());
                return;
            }

            if (con.connection != null) {
                this.setTitle("Java - PostgreSQL editor");
                JOptionPane.showMessageDialog(this, "Успешное подключение!",
                        "Подключено!", JOptionPane.INFORMATION_MESSAGE);
                ServerField.setEnabled(false);
                DBField.setEnabled(false);
                UserNameField.setEnabled(false);
                PassField.setEnabled(false);
                buttonConnect.setEnabled(false);
                enable_all();
                GetTableProduct(false, 0);
                break;
            } else {
                System.out.println("Ошибка подключения к базе данных");
            }
        }
    }

    private void GetTableProduct(boolean filter, int param){
        String s;
        if (!filter){
            s = "SELECT * FROM public.product";
        }
        else {
            s = String.format("SELECT * FROM public.product where price>%d", param);
        }
        ParseProd.setText("");
        Statement statement;
        ResultSet result;
        try {
            statement = con.connection.createStatement();
            result = statement.executeQuery(s);
            while(result.next()) {
                int id = result.getInt("id");
                String name = result.getString("name");
                String desc = result.getString("description");
                int price = result.getInt("price");
                ParseProd.append(String.format("id: %d, name: %s, desc: %s, price: %d\n", id, name, desc, price));
            }
            statement.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
        try {
            get_ids_prod(statement = con.connection.createStatement(), statement.executeQuery("SELECT * FROM public.product ORDER BY id"));
        } catch (SQLException e) {
            e.printStackTrace();
        }
        if (IDprod.getItemAt(0) == null){
            RemoveProd.setEnabled(false);
        }
        else {
            RemoveProd.setEnabled(true);
        }
    }


    private void AddItemProd() {
        String name = String.valueOf(namefield.getText());
        String email = String.valueOf(descfield.getText());
        if (namefield.getText() != null || descfield.getText() != null || pricefield.getText() != null) {
            int price = 0;
            try {
                price = Integer.parseInt(pricefield.getText());
            } catch (Exception e) {
                e.getMessage();
            } finally {
                if (price > 0) {
                    Statement statement;
                    try {
                        statement = con.connection.createStatement();
                        statement.execute(String.format("INSERT INTO public.product(name, description, price) values('%s', '%s', %d);", name, email, price));
                        statement.close();
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                    GetTableProduct(false, 0);
                } else {
                    JOptionPane.showMessageDialog(this, "Ошибка в поле \"цена\"!",
                            "Ошибка!", JOptionPane.ERROR_MESSAGE);
                }
            }
        }else{
            JOptionPane.showMessageDialog(this, "Все поля должны быть заполнены!",
                    "Ошибка!", JOptionPane.ERROR_MESSAGE);
        }
    }

    private void Update(){
        if (IDupd.getSelectedItem() != null && NameField2.getText().trim() != "" && DescField2.getText().trim() != "" && PriceField2.getText().trim() != ""){
            int price = 0;
            try{
                price = Integer.parseInt(PriceField2.getText());
            }
            catch (Exception e){
                e.getMessage();
            }
            finally {
                if (price > 0){
                    Statement statement;
                    try {
                        statement = con.connection.createStatement();
                        statement.execute(String.format("update product set (name, description, price) = ('%s', '%s', %d) where id = %s", NameField2.getText(), DescField2.getText(), price, IDupd.getSelectedItem()));
                        statement.close();
                    }
                    catch (Exception e){

                    }
                    GetTableProduct(false, 0);
                    JOptionPane.showMessageDialog(this, "Обновлено!!",
                            "Успех!", JOptionPane.INFORMATION_MESSAGE);
                }
                else{
                    JOptionPane.showMessageDialog(this, "Ошибка в поле \"цена\"!",
                            "Ошибка!", JOptionPane.ERROR_MESSAGE);
                }
            }
        }
        else{
            JOptionPane.showMessageDialog(this, "Все поля должны быть заполнены!",
                    "Ошибка!", JOptionPane.ERROR_MESSAGE);
        }
    }

    private void RemoveItemProd(){
        Statement statement;
        String ID = String.valueOf(IDprod.getSelectedItem());
        try {
            statement = con.connection.createStatement();
            statement.execute(String.format("DELETE FROM public.product WHERE ID=%s", ID));
            statement.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
        GetTableProduct(false, 0);
    }


    private void Filter_Prod(){
        int price = 0;
        try{
            price = Integer.parseInt(minprice.getText());
        }
        catch (Exception e){
            e.getMessage();
        }
        finally {
            if (price > 0) {
                GetTableProduct(true, price-1);
            }
            else {
                JOptionPane.showMessageDialog(this, "Цена должна быть положительной!",
                        "Ошибка!", JOptionPane.ERROR_MESSAGE);
            }
        }
    }

    public static void main(String[] args) {
        UI dialog = new UI();
        dialog.pack();
        dialog.setVisible(true);
        System.exit(0);
    }

    private void createUIComponents() {
        // TODO: place custom component creation code here
    }
}
