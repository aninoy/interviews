import bs4 as bs
import urllib.request
import pandas as pd

sauce = urllib.request.urlopen('https://pythonprogramming.net/parsememcparseface').read()
soup = bs.BeautifulSoup(sauce, 'lxml')
# print(soup)


print(soup.title.text)
# print(soup.p)
# print(soup.find_all('p'))

for para in soup.find_all('p'):
    print(para.text)

# print(soup.get_text())

# for url in soup.find_all('a'):
    # print(url.get('href'))

nav = soup.nav
for url in nav.find_all('a'):
    print(url.get('href'))

body = soup.body
for para in body.find_all('p'):
    print(para.text)

for div in soup.find_all('div', class_='body'):
    print(div.text)


table = soup.table
# table = soup.find('table')

table_rows = table.find_all('tr')
for tr in table_rows:
    td = tr.find_all('td')
    row = [i.text for i in td]
    print(row)

dfs = pd.read_html('https://pythonprogramming.net/parsememcparseface', header=0)
for df in dfs:
    print(df)

sitemap_sauce = urllib.request.urlopen('https://pythonprogramming.net/sitemap.xml').read()
soup = bs.BeautifulSoup(sitemap_sauce, 'xml')

for url in soup.find_all('loc'):
    print(url.text)

