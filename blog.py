# -*- coding: utf-8 -*-
import scrapy
from scrapy.http import Request
from urllib import parse
x=1
class BlogSpider(scrapy.Spider):
    name = 'blog'
    allowed_domains = ['blog.csdn.net']
    start_urls = ['https://blog.csdn.net/lights_joy/article/list/1']

    def parse(self, response):
        post_urls=response.css(".article-list a::attr(href)").extract()
        global x
        for post_url in post_urls:
            yield Request(url=parse.urljoin(response.url,post_url),callback=self.parse_detail)
            #yeild 关键字交给scrapy下载
        #提取下一页url
        x+=1
        if x<=19 :
            next_url=parse.urljoin(response.url,str(x))
            yield Request(next_url,callback=self.parse)

    def parse_detail(self,response):
        #提取文章具体字段
        title= response.xpath('//*[@id="mainBox"]/main/div[1]/div/div/div[1]/h1/text()').extract()[0]
        create_time = response.xpath('//span[@class="time"]/text()').extract()[0][5:]
        read_count = response.xpath('//span[@class="read-count"]/text()').extract()[0][3:]
        content = response.xpath('//div[@class="htmledit_views"]/p/text()').extract()[0]

        #css
        # title = response.css(".title-article::text")
        # time = response.css(".time::text").extract()[0].strip()
        # read = response.css(".read-count::text").extract()[0]
        # content = response.css(".htmledit_views p::text").extract()[0]
        pass
