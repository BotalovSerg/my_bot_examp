import time
import requests

from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from webdriver_manager.chrome import ChromeDriverManager
from selenium.webdriver.common.by import By


# Подключим движок браузера, если его нет, то сначала установим
service = Service(ChromeDriverManager().install())
driver = webdriver.Chrome(service=service)


def main():
    for i in range(1, 153):
        url = f"http://pokolenia.permkrai.ru/funds/view/76579#{i}"
        driver.get(url)
        time.sleep(2)
        div = driver.find_element(By.CLASS_NAME, "iviewer_cursor")
        url_image = div.find_element(By.TAG_NAME, "img").get_attribute("src")
        response = requests.get(url_image, stream=True)

        if response.status_code == 200:
            with open(f"book/page_{i}.jpg", "wb") as file:
                for chunk in response.iter_content(chunk_size=1024):
                    file.write(chunk)
                print(f"page_{i} done")
        else:
            print(f"Error iter {i} - status code: {response.status_code}")

if __name__ == "__main__":
    main()
