from multiprocessing import Pool
import bs4 as bs
import random
import string
import requests


def random_starting_url():
    starting = ''.join(random.SystemRandom().choice(string.ascii_lowercase) for _ in range(3))
    url = ''.join(['http://', starting, '.com'])
    return url


def handle_local_links(url, link):
    if link.startswith('/'):
        return ''.join(url, link)
    else:
        return link


def get_links(url):
    try:
        resp = requests.get(url)
        soup = bs.BeautifulSoup(resp.text, 'lxml')
        body = soup.body
        links = [link.get('href') for link in body.find_all('a')]
        links = [str(link.encode('ascii')) for link in links]
        return links

    except TypeError as e:
        print(e)
        print('TypeError')
        return []
    except IndexError as e:
        print(e)
        print('No useful links')
        return []
    except AttributeError as e:
        print(e)
        print('')
        return []
    except Exception as e:
        print(e)
        return []


def main():
    process_size = 50
    p = Pool(processes=process_size)
    parse_us = [random_starting_url() for _ in range(process_size)]
    data = p.map(get_links, [link for link in parse_us])
    data = [url for url_list in data for url in url_list]
    parse_us = data
    p.close()

    with open('urls.txt', 'w') as f:
        f.write(str(data))

if __name__ == '__main__':
    main()
