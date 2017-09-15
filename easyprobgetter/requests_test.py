import requests
from lxml import html
easy_prob=[]
index=5
if index<10:
    index="00"+str(index)
elif index<100:
    index="0"+str(index)
else:
    index=str(index)
url="https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category={}".format(index)
page=requests.get(url)
tree=html.fromstring(page.content)
raw_solve_rate=tree.xpath("//tr[@class='sectiontableentry1' or @class='sectiontableentry2']//td//div//div/text()")

raw_prob_title=tree.xpath("//tr[@class='sectiontableentry1' or @class='sectiontableentry2']//td//a/text()")

"""
Clean the data
"""

clean_titles=[]
for raw in raw_prob_title:
    clean_titles.append(raw[:4])

clean_solve_rate=[]
for i in range(len(raw_solve_rate)):
    if i % 2==1:
        if len(raw_solve_rate[i])==6:
            clean_solve_rate.append(float(raw_solve_rate[i][:5]))
        else:
            clean_solve_rate.append(float(raw_solve_rate[i][:4]))
# print(clean_titles)
rate_id=dict()
for title, rate in zip(clean_titles,clean_solve_rate):
    rate_id[title]=rate
for title in rate_id:
    if rate_id[title]>80:
        easy_prob.append(title)
print(easy_prob)
