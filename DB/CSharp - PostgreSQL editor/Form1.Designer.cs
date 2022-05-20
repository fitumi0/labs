namespace pgSQL
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.Table = new System.Windows.Forms.TabControl();
            this.AuthorisePage = new System.Windows.Forms.TabPage();
            this.ProgressBar = new System.Windows.Forms.ProgressBar();
            this.ConnBtn = new System.Windows.Forms.Button();
            this.PassField = new System.Windows.Forms.TextBox();
            this.UserField = new System.Windows.Forms.TextBox();
            this.PortField = new System.Windows.Forms.TextBox();
            this.DBField = new System.Windows.Forms.TextBox();
            this.ServerField = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.TablePage = new System.Windows.Forms.TabPage();
            this.label10 = new System.Windows.Forms.Label();
            this.MinPriceField = new System.Windows.Forms.TextBox();
            this.TBLE = new System.Windows.Forms.DataGridView();
            this.NameBox2 = new System.Windows.Forms.TextBox();
            this.DescriptionBox2 = new System.Windows.Forms.TextBox();
            this.PriceBox2 = new System.Windows.Forms.TextBox();
            this.NameBox = new System.Windows.Forms.TextBox();
            this.label9 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.DescriptionBox = new System.Windows.Forms.TextBox();
            this.PriceBox = new System.Windows.Forms.TextBox();
            this.UndoFilterBtn = new System.Windows.Forms.Button();
            this.FilterBtn = new System.Windows.Forms.Button();
            this.DeleteBtn = new System.Windows.Forms.Button();
            this.AddBtn = new System.Windows.Forms.Button();
            this.Update = new System.Windows.Forms.Button();
            this.label6 = new System.Windows.Forms.Label();
            this.Table.SuspendLayout();
            this.AuthorisePage.SuspendLayout();
            this.TablePage.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.TBLE)).BeginInit();
            this.SuspendLayout();
            // 
            // Table
            // 
            this.Table.Controls.Add(this.AuthorisePage);
            this.Table.Controls.Add(this.TablePage);
            this.Table.Font = new System.Drawing.Font("Consolas", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.Table.Location = new System.Drawing.Point(12, 12);
            this.Table.Name = "Table";
            this.Table.SelectedIndex = 0;
            this.Table.Size = new System.Drawing.Size(507, 467);
            this.Table.TabIndex = 0;
            // 
            // AuthorisePage
            // 
            this.AuthorisePage.Controls.Add(this.ProgressBar);
            this.AuthorisePage.Controls.Add(this.ConnBtn);
            this.AuthorisePage.Controls.Add(this.PassField);
            this.AuthorisePage.Controls.Add(this.UserField);
            this.AuthorisePage.Controls.Add(this.PortField);
            this.AuthorisePage.Controls.Add(this.DBField);
            this.AuthorisePage.Controls.Add(this.ServerField);
            this.AuthorisePage.Controls.Add(this.label5);
            this.AuthorisePage.Controls.Add(this.label4);
            this.AuthorisePage.Controls.Add(this.label3);
            this.AuthorisePage.Controls.Add(this.label2);
            this.AuthorisePage.Controls.Add(this.label1);
            this.AuthorisePage.Font = new System.Drawing.Font("Consolas", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.AuthorisePage.Location = new System.Drawing.Point(4, 23);
            this.AuthorisePage.Name = "AuthorisePage";
            this.AuthorisePage.Padding = new System.Windows.Forms.Padding(3);
            this.AuthorisePage.Size = new System.Drawing.Size(499, 440);
            this.AuthorisePage.TabIndex = 0;
            this.AuthorisePage.Text = "Авторизация";
            this.AuthorisePage.UseVisualStyleBackColor = true;
            // 
            // ProgressBar
            // 
            this.ProgressBar.Location = new System.Drawing.Point(-4, 421);
            this.ProgressBar.Name = "ProgressBar";
            this.ProgressBar.Size = new System.Drawing.Size(503, 23);
            this.ProgressBar.TabIndex = 11;
            this.ProgressBar.Visible = false;
            // 
            // ConnBtn
            // 
            this.ConnBtn.Font = new System.Drawing.Font("Consolas", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.ConnBtn.Location = new System.Drawing.Point(278, 261);
            this.ConnBtn.Name = "ConnBtn";
            this.ConnBtn.Size = new System.Drawing.Size(100, 23);
            this.ConnBtn.TabIndex = 10;
            this.ConnBtn.Text = "Подключиться";
            this.ConnBtn.UseVisualStyleBackColor = true;
            this.ConnBtn.Click += new System.EventHandler(this.ConnBtn_Click);
            // 
            // PassField
            // 
            this.PassField.Font = new System.Drawing.Font("Consolas", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.PassField.Location = new System.Drawing.Point(278, 232);
            this.PassField.Name = "PassField";
            this.PassField.PasswordChar = '#';
            this.PassField.Size = new System.Drawing.Size(100, 22);
            this.PassField.TabIndex = 9;
            this.PassField.Text = "1";
            // 
            // UserField
            // 
            this.UserField.Font = new System.Drawing.Font("Consolas", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.UserField.Location = new System.Drawing.Point(278, 203);
            this.UserField.Name = "UserField";
            this.UserField.Size = new System.Drawing.Size(100, 22);
            this.UserField.TabIndex = 8;
            this.UserField.Text = "user1";
            // 
            // PortField
            // 
            this.PortField.Enabled = false;
            this.PortField.Font = new System.Drawing.Font("Consolas", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.PortField.Location = new System.Drawing.Point(278, 174);
            this.PortField.Name = "PortField";
            this.PortField.Size = new System.Drawing.Size(100, 22);
            this.PortField.TabIndex = 7;
            this.PortField.Text = "5432";
            // 
            // DBField
            // 
            this.DBField.Font = new System.Drawing.Font("Consolas", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.DBField.Location = new System.Drawing.Point(278, 145);
            this.DBField.Name = "DBField";
            this.DBField.Size = new System.Drawing.Size(100, 22);
            this.DBField.TabIndex = 6;
            this.DBField.Text = "lab";
            // 
            // ServerField
            // 
            this.ServerField.Font = new System.Drawing.Font("Consolas", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.ServerField.Location = new System.Drawing.Point(278, 116);
            this.ServerField.Name = "ServerField";
            this.ServerField.Size = new System.Drawing.Size(100, 22);
            this.ServerField.TabIndex = 5;
            this.ServerField.Text = "localhost";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Consolas", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.label5.Location = new System.Drawing.Point(93, 235);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(63, 14);
            this.label5.TabIndex = 4;
            this.label5.Text = "Пароль: ";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Consolas", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.label4.Location = new System.Drawing.Point(93, 206);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(182, 14);
            this.label4.TabIndex = 3;
            this.label4.Text = "Пользователь [postgres]: ";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Consolas", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.label3.Location = new System.Drawing.Point(93, 177);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(98, 14);
            this.label3.TabIndex = 2;
            this.label3.Text = "Порт [5432]: ";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Consolas", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.label2.Location = new System.Drawing.Point(93, 148);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(126, 14);
            this.label2.TabIndex = 1;
            this.label2.Text = "База [postgres]: ";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Consolas", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.label1.Location = new System.Drawing.Point(93, 119);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(147, 14);
            this.label1.TabIndex = 0;
            this.label1.Text = "Сервер [localhost]: ";
            // 
            // TablePage
            // 
            this.TablePage.Controls.Add(this.label10);
            this.TablePage.Controls.Add(this.MinPriceField);
            this.TablePage.Controls.Add(this.TBLE);
            this.TablePage.Controls.Add(this.NameBox2);
            this.TablePage.Controls.Add(this.DescriptionBox2);
            this.TablePage.Controls.Add(this.PriceBox2);
            this.TablePage.Controls.Add(this.NameBox);
            this.TablePage.Controls.Add(this.label9);
            this.TablePage.Controls.Add(this.label8);
            this.TablePage.Controls.Add(this.label7);
            this.TablePage.Controls.Add(this.DescriptionBox);
            this.TablePage.Controls.Add(this.PriceBox);
            this.TablePage.Controls.Add(this.UndoFilterBtn);
            this.TablePage.Controls.Add(this.FilterBtn);
            this.TablePage.Controls.Add(this.DeleteBtn);
            this.TablePage.Controls.Add(this.AddBtn);
            this.TablePage.Controls.Add(this.Update);
            this.TablePage.Controls.Add(this.label6);
            this.TablePage.Font = new System.Drawing.Font("Consolas", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.TablePage.Location = new System.Drawing.Point(4, 23);
            this.TablePage.Name = "TablePage";
            this.TablePage.Padding = new System.Windows.Forms.Padding(3);
            this.TablePage.Size = new System.Drawing.Size(499, 440);
            this.TablePage.TabIndex = 1;
            this.TablePage.Text = "Таблица: PRODUCT";
            this.TablePage.UseVisualStyleBackColor = true;
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Font = new System.Drawing.Font("Consolas", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.label10.Location = new System.Drawing.Point(187, 147);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(126, 14);
            this.label10.TabIndex = 19;
            this.label10.Text = "Минимальная цена:";
            // 
            // MinPriceField
            // 
            this.MinPriceField.Location = new System.Drawing.Point(340, 144);
            this.MinPriceField.Name = "MinPriceField";
            this.MinPriceField.Size = new System.Drawing.Size(72, 22);
            this.MinPriceField.TabIndex = 18;
            // 
            // TBLE
            // 
            this.TBLE.AllowUserToAddRows = false;
            this.TBLE.AllowUserToDeleteRows = false;
            this.TBLE.BackgroundColor = System.Drawing.SystemColors.Control;
            this.TBLE.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.TBLE.Location = new System.Drawing.Point(0, 20);
            this.TBLE.MultiSelect = false;
            this.TBLE.Name = "TBLE";
            this.TBLE.ReadOnly = true;
            this.TBLE.RowTemplate.Height = 25;
            this.TBLE.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.TBLE.Size = new System.Drawing.Size(493, 118);
            this.TBLE.TabIndex = 17;
            this.TBLE.CellClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.TBLE_CellClick);
            // 
            // NameBox2
            // 
            this.NameBox2.Enabled = false;
            this.NameBox2.Font = new System.Drawing.Font("Consolas", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.NameBox2.Location = new System.Drawing.Point(3, 271);
            this.NameBox2.Name = "NameBox2";
            this.NameBox2.Size = new System.Drawing.Size(147, 22);
            this.NameBox2.TabIndex = 15;
            // 
            // DescriptionBox2
            // 
            this.DescriptionBox2.Enabled = false;
            this.DescriptionBox2.Font = new System.Drawing.Font("Consolas", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.DescriptionBox2.Location = new System.Drawing.Point(156, 271);
            this.DescriptionBox2.Name = "DescriptionBox2";
            this.DescriptionBox2.Size = new System.Drawing.Size(178, 22);
            this.DescriptionBox2.TabIndex = 14;
            // 
            // PriceBox2
            // 
            this.PriceBox2.Enabled = false;
            this.PriceBox2.Font = new System.Drawing.Font("Consolas", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.PriceBox2.Location = new System.Drawing.Point(340, 271);
            this.PriceBox2.Name = "PriceBox2";
            this.PriceBox2.Size = new System.Drawing.Size(72, 22);
            this.PriceBox2.TabIndex = 13;
            // 
            // NameBox
            // 
            this.NameBox.Font = new System.Drawing.Font("Consolas", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.NameBox.Location = new System.Drawing.Point(3, 243);
            this.NameBox.Name = "NameBox";
            this.NameBox.Size = new System.Drawing.Size(147, 22);
            this.NameBox.TabIndex = 12;
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Font = new System.Drawing.Font("Consolas", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.label9.Location = new System.Drawing.Point(340, 203);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(35, 14);
            this.label9.TabIndex = 11;
            this.label9.Text = "Цена";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Font = new System.Drawing.Font("Consolas", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.label8.Location = new System.Drawing.Point(206, 203);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(63, 14);
            this.label8.TabIndex = 10;
            this.label8.Text = "Описание";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Font = new System.Drawing.Font("Consolas", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.label7.Location = new System.Drawing.Point(6, 203);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(63, 14);
            this.label7.TabIndex = 9;
            this.label7.Text = "Название";
            // 
            // DescriptionBox
            // 
            this.DescriptionBox.Font = new System.Drawing.Font("Consolas", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.DescriptionBox.Location = new System.Drawing.Point(156, 243);
            this.DescriptionBox.Name = "DescriptionBox";
            this.DescriptionBox.Size = new System.Drawing.Size(178, 22);
            this.DescriptionBox.TabIndex = 8;
            // 
            // PriceBox
            // 
            this.PriceBox.Font = new System.Drawing.Font("Consolas", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.PriceBox.Location = new System.Drawing.Point(340, 243);
            this.PriceBox.Name = "PriceBox";
            this.PriceBox.Size = new System.Drawing.Size(72, 22);
            this.PriceBox.TabIndex = 7;
            // 
            // UndoFilterBtn
            // 
            this.UndoFilterBtn.Font = new System.Drawing.Font("Consolas", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.UndoFilterBtn.Location = new System.Drawing.Point(418, 174);
            this.UndoFilterBtn.Name = "UndoFilterBtn";
            this.UndoFilterBtn.Size = new System.Drawing.Size(75, 23);
            this.UndoFilterBtn.TabIndex = 6;
            this.UndoFilterBtn.Text = "Сброс";
            this.UndoFilterBtn.UseVisualStyleBackColor = true;
            this.UndoFilterBtn.Click += new System.EventHandler(this.UndoFilterBtn_Click);
            // 
            // FilterBtn
            // 
            this.FilterBtn.Font = new System.Drawing.Font("Consolas", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.FilterBtn.Location = new System.Drawing.Point(418, 145);
            this.FilterBtn.Name = "FilterBtn";
            this.FilterBtn.Size = new System.Drawing.Size(75, 23);
            this.FilterBtn.TabIndex = 5;
            this.FilterBtn.Text = "Фильтр";
            this.FilterBtn.UseVisualStyleBackColor = true;
            this.FilterBtn.Click += new System.EventHandler(this.FilterBtn_Click);
            // 
            // DeleteBtn
            // 
            this.DeleteBtn.Enabled = false;
            this.DeleteBtn.Font = new System.Drawing.Font("Consolas", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.DeleteBtn.Location = new System.Drawing.Point(418, 298);
            this.DeleteBtn.Name = "DeleteBtn";
            this.DeleteBtn.Size = new System.Drawing.Size(75, 23);
            this.DeleteBtn.TabIndex = 4;
            this.DeleteBtn.Text = "Удалить";
            this.DeleteBtn.UseVisualStyleBackColor = true;
            this.DeleteBtn.Click += new System.EventHandler(this.DeleteBtn_Click);
            // 
            // AddBtn
            // 
            this.AddBtn.Font = new System.Drawing.Font("Consolas", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.AddBtn.Location = new System.Drawing.Point(418, 243);
            this.AddBtn.Name = "AddBtn";
            this.AddBtn.Size = new System.Drawing.Size(75, 23);
            this.AddBtn.TabIndex = 3;
            this.AddBtn.Text = "Добавить";
            this.AddBtn.UseVisualStyleBackColor = true;
            this.AddBtn.Click += new System.EventHandler(this.AddBtn_Click);
            // 
            // Update
            // 
            this.Update.Font = new System.Drawing.Font("Consolas", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.Update.Location = new System.Drawing.Point(418, 271);
            this.Update.Name = "Update";
            this.Update.Size = new System.Drawing.Size(75, 23);
            this.Update.TabIndex = 2;
            this.Update.Text = "Обновить";
            this.Update.UseVisualStyleBackColor = true;
            this.Update.Click += new System.EventHandler(this.Update_Click);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Consolas", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.label6.Location = new System.Drawing.Point(161, 3);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(119, 14);
            this.label6.TabIndex = 0;
            this.label6.Text = "Таблица: PRODUCT";
            this.label6.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(525, 485);
            this.Controls.Add(this.Table);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
            this.Name = "Form1";
            this.Text = "C# - PostgreSQL editor";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.Table.ResumeLayout(false);
            this.AuthorisePage.ResumeLayout(false);
            this.AuthorisePage.PerformLayout();
            this.TablePage.ResumeLayout(false);
            this.TablePage.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.TBLE)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private TabControl Table;
        private TabPage AuthorisePage;
        private TabPage TablePage;
        private TextBox PassField;
        private TextBox UserField;
        private TextBox PortField;
        private TextBox DBField;
        private TextBox ServerField;
        private Label label5;
        private Label label4;
        private Label label3;
        private Label label2;
        private Label label1;
        private Button ConnBtn;
        private Label label6;
        private Button Update;
        private Button AddBtn;
        private TextBox DescriptionBox;
        private TextBox PriceBox;
        private Button UndoFilterBtn;
        private Button FilterBtn;
        private Button DeleteBtn;
        private TextBox NameBox;
        private Label label9;
        private Label label8;
        private Label label7;
        private TextBox NameBox2;
        private TextBox DescriptionBox2;
        private TextBox PriceBox2;
        private DataGridView TBLE;
        private ProgressBar ProgressBar;
        private Label label10;
        private TextBox MinPriceField;
        private Label label11;
    }
}