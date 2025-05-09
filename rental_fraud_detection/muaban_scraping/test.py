import json
import random
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.action_chains import ActionChains
import pickle
import time 
import os
import pyautogui
import chardet

chrome_options = webdriver.ChromeOptions()
chrome_options.add_argument('--start-maximized')
driver = webdriver.Chrome(options=chrome_options)
driver.get("https://muaban.net/bat-dong-san/cho-thue-nha-tro-phong-tro-ho-chi-minh")
screen_width, screen_height = pyautogui.size()
window_size = driver.get_window_size()
login_button = WebDriverWait(driver, 10).until(
            EC.presence_of_element_located((By.CSS_SELECTOR, ".sc-18oo25t-9.kfohvY li:nth-child(2)"))
        )
element_location = login_button.location
element_size = login_button.size
print(screen_height, screen_width, window_size, element_location, element_size)


def move_and_click(driver, element, duration=1):
    """Di chuyển chuột và nhấp vào một phần tử dựa trên vị trí của nó trong cửa sổ."""
    # Lấy kích thước cửa sổ trình duyệt
    window_size = driver.get_window_size()
    window_width = window_size['width']
    window_height = window_size['height']

    # Lấy vị trí và kích thước của phần tử
    element_location = element.location
    element_size = element.size

    # Tính toán vị trí trung tâm của phần tử
    element_center_x = element_location['x'] + element_size['width'] / 2 - 100
    element_center_y = element_location['y'] + element_size['height'] / 2 - 200

    # Tính toán vị trí trên màn hình (tương thích với pyautogui)
    screen_width, screen_height = pyautogui.size()
    x_ratio = element_center_x / window_width
    y_ratio = element_center_y / window_height
    screen_x = x_ratio * screen_width
    screen_y = y_ratio * screen_height

    # Di chuyển chuột và nhấp
    pyautogui.moveTo(screen_x, screen_y, duration=duration)
    pyautogui.click()


def find_buttons(driver):
    """Tìm và nhấp vào các nút sử dụng pyautogui để đảm bảo tự nhiên hơn."""
    try:
        # Tìm nút Login
        login_button = WebDriverWait(driver, 10).until(
            EC.presence_of_element_located((By.CSS_SELECTOR, ".sc-18oo25t-9.kfohvY li:nth-child(2)"))
        )
        move_and_click(driver, login_button)
        time.sleep(5)

        # Tìm nút Google Login
        google_button = WebDriverWait(driver, 10).until(
            EC.presence_of_element_located((By.CSS_SELECTOR, ".sc-sc4voz-24.sc-sc4voz-26.cWUgUg.dQitXM"))
        )
        move_and_click(driver, google_button)
        time.sleep(5)

    except Exception as e:
        print("Lỗi khi tìm và nhấp vào nút:", e)


def login_google(driver, username, password):
    """Nhập thông tin đăng nhập Google bằng pyautogui."""
    try:
        # Nhập email
        email_input = WebDriverWait(driver, 10).until(
            EC.presence_of_element_located((By.CSS_SELECTOR, 'input[type="email"]'))
        )
        move_and_click(driver, email_input)
        for char in username:
            pyautogui.typewrite(char, interval=0.1)
        time.sleep(2)

        # Nhấp vào nút Tiếp theo
        next1 = WebDriverWait(driver, 10).until(
            EC.presence_of_element_located((By.CSS_SELECTOR, 'div[jsname="k77Iif"] button[jsname="LgbsSe"]'))
        )
        move_and_click(driver, next1)
        time.sleep(5)

        # Nhập mật khẩu
        password_input = WebDriverWait(driver, 10).until(
            EC.presence_of_element_located((By.CSS_SELECTOR, 'input[type="password"]'))
        )
        move_and_click(driver, password_input)
        for char in password:
            pyautogui.typewrite(char, interval=0.1)
        time.sleep(2)

        # Nhấp vào nút Tiếp theo
        next2 = WebDriverWait(driver, 10).until(
            EC.presence_of_element_located((By.CSS_SELECTOR, 'div[jsname="k77Iif"] button[jsname="LgbsSe"]'))
        )
        move_and_click(driver, next2)
        time.sleep(5)

    except Exception as e:
        print("Lỗi khi đăng nhập Google:", e)

def convert_json_to_pkl(json_file, pkl_file):
    try:
        # Load JSON data
        with open(json_file, 'r') as f:
            data = json.load(f)

        # Save data as a pickle file
        with open(pkl_file, 'wb') as f:
            pickle.dump(data, f)

        print(f"Successfully converted {json_file} to {pkl_file}.")
    except Exception as e:
        print(f"An error occurred: {e}")
        

# Hàm phát hiện encoding của file
def detect_encoding(file_path):
    with open(file_path, 'rb') as f:
        result = chardet.detect(f.read())
    return result['encoding']

# Chuyển file CSV sang UTF-8
def convert_csv_to_utf8(input_file, output_file):
    # Phát hiện encoding gốc
    encoding = detect_encoding(input_file)
    print(f"Detected encoding: {encoding}")

    # Đọc file với encoding gốc và ghi lại với UTF-8
    with open(input_file, 'r', encoding=encoding) as infile:
        content = infile.read()
    with open(output_file, 'w', encoding='utf-8') as outfile:
        outfile.write(content)
    print(f"File has been converted to UTF-8: {output_file}")
    
def random_click(clicks=2):
    for _ in range(clicks):
        # Random delay before the click
        time.sleep(random.uniform(1.0, 3.0))
        
        # Random position click
        x1 = random.randint(0, pyautogui.size().width - 1)
        y1 = random.randint(0, pyautogui.size().height - 1)
        pyautogui.moveTo(x1, y1, duration=random.uniform(0.5, 1.5))
        
        '''
        # Random left or right click
        click_type = random.choice(['left', 'right'])
        pyautogui.click(button=click_type)
        pyautogui.click(button='right')
        '''
        
        # Slight pause between clicks
        time.sleep(random.uniform(0.2, 1.0))
        
def is_logged_in(driver):
    try:
        login_site = driver.find_element(By.CSS_SELECTOR, ".sc-18oo25t-9.kfohvY li:nth-child(2)")
        login_name = driver.find_element(By.CSS_SELECTOR, ".sc-18oo25t-9.kfohvY li:nth-child(3)")
        if login_site.text == "Quản lý tin" and login_name == "IT Tech":
            return True
        else: return False
    except:
        print("Error!")
        return