import tkinter as tk
from tkinter import Label, Button
import random
import pyodbc
import matplotlib.pyplot as plt
from datetime import datetime
import threading
import time

# Cấu hình kết nối SQL Server
SERVER = 'localhost'  # Thay bằng tên server của bạn
DATABASE = 'AirQuality'  # Tên database
# USERNAME = ''  # Username SQL Server
# PASSWORD = 'Ngocty1912'  # Password SQL Server

# Kết nối SQL Server
#conn = pyodbc.connect(f'DRIVER={{SQL Server}};SERVER={SERVER};DATABASE={DATABASE};UID={USERNAME};PWD={PASSWORD}')
#conn = pyodbc.connect(f'DRIVER={{SQL Server}};SERVER={SERVER};DATABASE={DATABASE};Trusted_Connection=yes;')
conn = pyodbc.connect(f'DRIVER={{SQL Server}};SERVER={SERVER};DATABASE=master;Trusted_Connection=yes;')
cursor = conn.cursor()

# Tạo bảng nếu chưa có
cursor.execute("""
IF NOT EXISTS (SELECT * FROM sysobjects WHERE name='AirQuality' AND xtype='U')
CREATE TABLE AirQuality (
    ID INT IDENTITY(1,1) PRIMARY KEY,
    Timestamp DATETIME,
    PM25 FLOAT,
    CO2 FLOAT,
    Temperature FLOAT,
    Humidity FLOAT
)
""")
conn.commit()

# Hàm cập nhật dữ liệu giả lập
def update_air_quality():
    while True:
        pm25 = random.uniform(5, 300)  # Chỉ số bụi mịn PM2.5 (µg/m³)
        co2 = random.uniform(300, 5000)  # Nồng độ CO2 (ppm)
        temp = random.uniform(15, 40)  # Nhiệt độ (°C)
        humidity = random.uniform(20, 90)  # Độ ẩm (%)

        timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        cursor.execute("INSERT INTO AirQuality (Timestamp, PM25, CO2, Temperature, Humidity) VALUES (?, ?, ?, ?, ?)",
                       (timestamp, pm25, co2, temp, humidity))
        conn.commit()

        # Cập nhật giao diện
        app.update_display(pm25, co2, temp, humidity)

        time.sleep(2)  # Cập nhật mỗi 2 giây

# Hàm hiển thị dữ liệu trên biểu đồ
def show_chart():
    cursor.execute("SELECT TOP 10 Timestamp, PM25, CO2, Temperature, Humidity FROM AirQuality ORDER BY ID DESC")
    data = cursor.fetchall()

    if data:
        timestamps, pm25_values, co2_values, temp_values, humidity_values = zip(*data)

        plt.figure(figsize=(8, 4))
        plt.plot(timestamps, pm25_values, marker='o', linestyle='-', color='red', label="PM2.5")
        plt.plot(timestamps, co2_values, marker='s', linestyle='-', color='blue', label="CO2")
        plt.plot(timestamps, temp_values, marker='^', linestyle='-', color='green', label="Nhiệt độ")
        plt.plot(timestamps, humidity_values, marker='x', linestyle='-', color='orange', label="Độ ẩm")
        
        plt.xlabel("Thời gian")
        plt.ylabel("Giá trị đo")
        plt.xticks(rotation=45)
        plt.title("Chất lượng không khí trong 10 lần đo gần nhất")
        plt.legend()
        plt.grid()
        plt.show()
    else:
        print("Không có dữ liệu để hiển thị!")

# Lớp giao diện chính
class AirQualityApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Giám sát Chất lượng Không Khí")

        Label(root, text="Hệ thống giám sát không khí", font=("Arial", 16, "bold")).pack()

        self.pm25_label = Label(root, text="PM2.5: -- µg/m³", font=("Arial", 14))
        self.pm25_label.pack()

        self.co2_label = Label(root, text="CO2: -- ppm", font=("Arial", 14))
        self.co2_label.pack()

        self.temp_label = Label(root, text="Nhiệt độ: -- °C", font=("Arial", 14))
        self.temp_label.pack()

        self.humidity_label = Label(root, text="Độ ẩm: -- %", font=("Arial", 14))
        self.humidity_label.pack()

        self.warning_label = Label(root, text="", font=("Arial", 14, "bold"), fg="red")
        self.warning_label.pack()

        Button(root, text="Xem biểu đồ chất lượng không khí", command=show_chart, font=("Arial", 12)).pack(pady=10)

    # Hàm cập nhật giao diện với dữ liệu mới
    def update_display(self, pm25, co2, temp, humidity):
        self.pm25_label.config(text=f"PM2.5: {pm25:.2f} µg/m³")
        self.co2_label.config(text=f"CO2: {co2:.2f} ppm")
        self.temp_label.config(text=f"Nhiệt độ: {temp:.2f} °C")
        self.humidity_label.config(text=f"Độ ẩm: {humidity:.2f} %")

        # Cảnh báo nếu không khí ô nhiễm
        if pm25 > 100 or co2 > 1000:
            self.warning_label.config(text="⚠️ CẢNH BÁO: Không khí ô nhiễm!", fg="red")
        else:
            self.warning_label.config(text="🌿 Không khí trong lành", fg="green")

# Khởi tạo ứng dụng
root = tk.Tk()
app = AirQualityApp(root)

# Chạy cập nhật dữ liệu trong luồng riêng
threading.Thread(target=update_air_quality, daemon=True).start()

# Chạy giao diện
root.mainloop()
