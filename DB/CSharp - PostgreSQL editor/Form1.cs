using System;
using System.Data;
using System.Collections;
using System.Windows.Forms;
using Npgsql;

namespace pgSQL
{
    public partial class Form1 : Form

    {
        private string connString;
        private NpgsqlConnection conn;
        private NpgsqlCommand cmd;
        private DataTable dt;
        private string sql;
        private string id;
        private string name;
        private string description;
        private string price;
        private bool selected;
    public Form1()
        {
            InitializeComponent();
            TablePage.Enabled = false;

        }

        private void Form1_Load(object sender, EventArgs e)
        {
        }

        private void GetTable()
        {   
            cmd = new NpgsqlCommand("SELECT * FROM product", conn);
            dt = new DataTable();
            dt.Load(cmd.ExecuteReader());
            TBLE.DataSource = null;
            TBLE.DataSource = dt;
            conn.Close();
        }
        private void disable_objects()
        {
            AuthorisePage.Enabled = false;
            TablePage.Enabled = true;
        }

        private void ConnBtn_Click(object sender, EventArgs e)
        {
            try
            {
                connString = $"Host={ServerField.Text};Username={UserField.Text};Password={PassField.Text};Database={DBField.Text}";
                conn = new NpgsqlConnection(connString);
                conn.Open();
                disable_objects();
                ProgressBar.Visible = true;
                while (ProgressBar.Value < 100)
                {
                    ProgressBar.Value++;
                }
                MessageBox.Show("Успешно подключено", "Статус подключения",
                MessageBoxButtons.OK, MessageBoxIcon.Information);
                ConnBtn.Text = "Подключено";
                try
                {
                    GetTable();
                }
                catch (Exception ex)
                {
                    MessageBox.Show("Ошибка чтения базы данных!\n\n" + ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
                finally { ProgressBar.Visible = false; }
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Проверьте данные для подключения.\n\nОшибка: {ex}", "Ошибка подключения",
                    MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            finally
            {
                conn.Close();
            }
        }

        private void DeleteBtn_Click(object sender, EventArgs e)
        {
            conn.Open();
            try
            {
                cmd = new NpgsqlCommand($"DELETE FROM product where id='{id}'", conn);
                NpgsqlDataReader reader = cmd.ExecuteReader();
                MessageBox.Show("Удалено!", "Успех!", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            finally
            {
                conn.Close();
                conn.Open();
                GetTable();
                NameBox2.Text = string.Empty;
                DescriptionBox2.Text = string.Empty;
                PriceBox2.Text = string.Empty;
                NameBox2.Enabled = false;
                DescriptionBox2.Enabled = false;
                PriceBox2.Enabled = false;
                DeleteBtn.Enabled = false;
                selected = false;
            }
        }

        private void FilterBtn_Click(object sender, EventArgs e)
        {
            int qty = 0;
            try
            {
                qty = Convert.ToInt32(MinPriceField.Text);
                if (qty < 1) { throw new Exception(); }
            }
            catch
            {
                MessageBox.Show("Ошибка в поле фильтрации!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            try
            {
                conn.Open();
                cmd = new NpgsqlCommand($"SELECT * FROM product where price>{MinPriceField.Text}-1", conn);
                dt = new DataTable();
                dt.Load(cmd.ExecuteReader());
                TBLE.DataSource = null;
                TBLE.DataSource = dt;

            }
            catch (Exception ex)
            {
                MessageBox.Show("Ошибка чтения базы данных!\n\n" + ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            finally
            {
                conn.Close();
            }
        }

        private void UndoFilterBtn_Click(object sender, EventArgs e)
        {
            try
            {
                conn.Open();
                GetTable();
            }
            catch(Exception ex)
            {
                MessageBox.Show("Ошибка чтения базы данных!\n\n" + ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void AddBtn_Click(object sender, EventArgs e)
        {
            if (NameBox.Text == string.Empty || DescriptionBox.Text == string.Empty || PriceBox.Text == string.Empty)
            {
                MessageBox.Show("Все поля должны быть заполнены!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            int price_ = 0;
            try
            {
                price_ = Convert.ToInt32(PriceBox.Text);
                if (price_ <= 0)
                { throw new Exception(); }
            }
            catch
            {
                MessageBox.Show("Ошибка в поле цены!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            conn.Open();
            try
            {
                cmd = new NpgsqlCommand($"INSERT INTO product(name, description, price) values('{NameBox.Text}', '{DescriptionBox.Text}', {PriceBox.Text})", conn);
                NpgsqlDataReader reader = cmd.ExecuteReader();
                MessageBox.Show("Добавлено!", "Успех!", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            finally
            {
                conn.Close();
                conn.Open();
                GetTable();
                NameBox.Text = string.Empty;
                DescriptionBox.Text = string.Empty;
                PriceBox.Text = string.Empty;

            }
        }

        private void Update_Click(object sender, EventArgs e)
        {
            if (!selected)
            {
                MessageBox.Show("Объект не выбран!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            int price_ = 0;
            try
            {
                price_ = Convert.ToInt32(PriceBox.Text);
                if (price_ <= 0)
                {
                    throw (new Exception());
                }
            }
            catch
            {
                if (PriceBox2.Text != string.Empty && price_ < 0)
                {
                    MessageBox.Show("Ошибка в поле цены!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return;
                }
            }
            if (NameBox2.Text == string.Empty)
            {
                NameBox2.Text = name;
            }
            if (DescriptionBox2.Text == string.Empty)
            {
                DescriptionBox2.Text = description;
            }
            if (PriceBox2.Text == string.Empty)
            {
                PriceBox2.Text = price;
            }
            try
            {
                conn.Open();
                cmd = new NpgsqlCommand($"update product set (name, description, price) = ('{NameBox2.Text}', '{DescriptionBox2.Text}', {PriceBox2.Text}) where id = {id}", conn);
                NpgsqlDataReader reader = cmd.ExecuteReader();
                MessageBox.Show("Обновлено!", "Успех!", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            catch (Exception ex){
                MessageBox.Show(ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            finally
            {
                conn.Close();
                conn.Open();
                GetTable();
                NameBox2.Text = string.Empty;
                DescriptionBox2.Text = string.Empty;
                PriceBox2.Text = string.Empty;
                NameBox2.Enabled = false;
                DescriptionBox2.Enabled = false;
                PriceBox2.Enabled = false;
                DeleteBtn.Enabled = false;
                selected = false;

            }
        }



        private void TBLE_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            if (e.RowIndex >= 0)
            {
                NameBox2.Enabled = true;
                DescriptionBox2.Enabled = true;
                PriceBox2.Enabled = true;
                DeleteBtn.Enabled = true;
                DataGridViewRow row = TBLE.Rows[e.RowIndex];
                id = row.Cells[0].Value.ToString();
                name = row.Cells[1].Value.ToString();
                description = row.Cells[2].Value.ToString();
                price = row.Cells[3].Value.ToString();
                selected = true;
                NameBox2.Text = name;
                DescriptionBox2.Text = description;
                PriceBox2.Text = price;
            }
            else
            {
                NameBox2.Text = string.Empty;
                DescriptionBox2.Text = string.Empty;
                PriceBox2.Text = string.Empty;
                NameBox2.Enabled = false;
                DescriptionBox2.Enabled = false;
                PriceBox2.Enabled = false;
                DeleteBtn.Enabled = false;
                selected = false;
            }
        }
    }
}