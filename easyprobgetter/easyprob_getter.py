__author__="Chufan Xiao"
from lxml import html
import requests
import time
def getEasyProblems(ace_rate):
    easy_prob=[]
    easy_prob_rate=[]
    for index in range(3,750):
        if index<10:
            index="00"+str(index)
        elif index<100:
            index="0"+str(index)
        else:
            index=str(index)
        url="https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category={}".format(index)
        try:
            page=requests.get(url)
            time.sleep(10)
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
                    if raw_solve_rate[i]=="NO SUBMISSIONS":
                        clean_solve_rate.append(float(0))
                    elif len(raw_solve_rate[i])==6:
                        clean_solve_rate.append(float(raw_solve_rate[i][:5]))
                    else:
                        clean_solve_rate.append(float(raw_solve_rate[i][:4]))
            # print(clean_titles)
            rate_id=dict()
            for title, rate in zip(clean_titles,clean_solve_rate):
                rate_id[title]=rate
            for title in rate_id:
                if rate_id[title]>float(ace_rate):
                    easy_prob.append(title)
                    easy_prob_rate.append(rate_id[title])
            print(easy_prob)
        except requests.exceptions.RequestException as e:
            print(e)
    output=open("icpc-easy-prob.txt","w")
    for title, rate in zip(easy_prob,easy_prob_rate):
        output.write("{}    {}".format(title,rate))


if __name__=="__main__":
    your_preferred_ace_rate=input("Enter your preferred ace rate: ")
    getEasyProblems(your_preferred_ace_rate)
