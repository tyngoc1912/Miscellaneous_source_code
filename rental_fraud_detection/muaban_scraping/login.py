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
import random

def get_driver(driver_num = 1):
    chrome_options = webdriver.ChromeOptions()
    
    user_agent_string = 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/119.0.0.0 Safari/537.36'
    chrome_options.add_argument(f"user-agent={user_agent_string}")
    chrome_options.add_argument('--start-maximized')
    chrome_options.add_argument('--disable-notifications')
    chrome_options.add_argument('--disable-web-security')
    chrome_options.add_argument('--allow-running-insecure-content')
    chrome_options.add_argument('--disable-blink-features=AutomationControlled')
    chrome_options.add_experimental_option('excludeSwitches', ['enable-automation'])
    
    chrome_service = Service(f'D:/TYNGOC/CNTT/A_Code/python/Rental_Fraud_Detection_Project/driver/chromedriver-win64_{str(driver_num)}/chromedriver.exe')
    driver = webdriver.Chrome(options=chrome_options, service=chrome_service)
    driver.implicitly_wait(5)
    return driver  

def random_mouse_movement(duration=5):
    """Simulates human-like random mouse movements with pauses and diverse patterns."""
    start_time = time.time()
    screen_width, screen_height = pyautogui.size()
    
    while time.time() - start_time < duration:
        # Random target position
        x1 = random.randint(0, screen_width - 1)
        y1 = random.randint(0, screen_height - 1)
        # Random movement duration
        move_duration = random.uniform(0.3, 2.0)
        # Move the mouse with some randomness
        pyautogui.moveTo(x1, y1, duration=move_duration)
        
        # Random pause between movements
        pause = random.uniform(0.5, 2.0)
        time.sleep(pause)
        

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

def random_scroll(duration=5, max_scroll=500):
    start_time = time.time()

    while time.time() - start_time < duration:
        # Randomize the scroll distance
        scroll_distance = random.randint(-max_scroll, max_scroll)
        
        # Perform the scroll
        pyautogui.scroll(scroll_distance)
        
        # Randomize the pause between scrolls
        pause = random.uniform(0.5, 2.0)
        time.sleep(pause)

def human_like_pause():
    pause_duration = random.uniform(1.0, 3.0)
    time.sleep(pause_duration)

def move_click(path):
    x, y = pyautogui.locateCenterOnScreen(path, confidence=0.9)
    move_duration = random.uniform(0.5, 1)
    pyautogui.moveTo(x, y, duration=move_duration)
    pyautogui.click()
    time.sleep(5)

def typing(text, include_typo=True):
    for char in text:
        delay = random.uniform(0.05, 0.3)
        pyautogui.typewrite(char, interval=delay)
    
        if include_typo and random.random() < 0.1:  # 10% chance of typo
            typo_char = random.choice('abcdefghijklmnopqrstuvwxyz')
            pyautogui.typewrite(typo_char)
            time.sleep(random.uniform(0.2, 0.5))
            pyautogui.press('backspace')
    time.sleep(5)
    
def perform(username, password):
    login_button = "./images/login_button.png"
    google_button = "./images/google_button.png"
    email_button = "./images/email2.png"
    password_button = "./images/password2.png"
    next_button = "./images/next_button.png"
    
    random_mouse_movement(3)
    human_like_pause()
    move_click(login_button)
    human_like_pause()
    random_click(1)
    random_scroll(1)
    move_click(google_button)
    human_like_pause()
    random_mouse_movement(3)
    move_click(email_button)
    typing(username)
    human_like_pause()
    random_click(1)
    move_click(next_button)
    human_like_pause()
    move_click(password_button)
    typing(password)
    human_like_pause()
    move_click(next_button)

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

def save_cookies(driver, username):
    name = username.split('@')
    path = f"muaban_cookies_{str(name[0])}.pkl"
    pickle.dump(driver.get_cookies(), open(path,"wb"))
    return path

def load_cookies(driver, scrap_url, path):
    cookies = pickle.load(open(path, "rb"))
        
    for cookie in cookies:
        driver.add_cookie(cookie)
        driver.get(scrap_url)

    driver.refresh()
        
def first_login(scrap_url, username, password, path, driver_num=1):
    try:
        driver = get_driver(driver_num)
        driver.get(scrap_url)
        '''
        check_login = False
        while not check_login:
            perform(username, password)
            check_login = is_logged_in(driver)
        '''
        perform(username, password)
        time.sleep(20)    
        path = save_cookies(driver, username)
        return path
    except Exception as e:
        print(f"Error {e}")
    finally:
        driver.quit()

def login_by_cookies(scrap_url, path, driver_num=1): 
    try:
        driver = get_driver(driver_num)
        driver.get(scrap_url)
        time.sleep(5)
        load_cookies(driver, scrap_url, path)    
    except Exception as e:
        print(f"Error {e}")
    finally:
        driver.quit()
                       
def login(scrap_url, username, password, path, driver_num):
    try:
        if os.path.exists(path):
            login_by_cookies(scrap_url, path, driver_num)
        else:
            path = first_login(scrap_url, username, password, path, driver_num)
    except Exception as e:
        print(f"Error {e}")
        
if __name__ == "__main__":
    
    scrap_url = "https://muaban.net/bat-dong-san/cho-thue-nha-tro-phong-tro-ho-chi-minh"
    
    #username = "hoangvinhcolab1@gmail.com"
    #password = "Songchetmacbay0"
    
    username = "ittechcolab@gmail.com"
    password = "Ittech1912@%#"
    name = "ittechcolab"
    
    path = f"muaban_cookies_{str(name)}.pkl"
    
    login(scrap_url, username, password, path, 1)