#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:     short example of adding header-customized urls, to download 
#              user-agent-checked/-constrained resources
#
# Author:      Lo Sauer
#
# Created:     12.06.2010
# Licence:     public domain
#-------------------------------------------------------------------------------
#!/usr/bin/env python

def main():
    import urllib2
    furl = urllib2.Request('http://www.example.org/rest/in/peace')
    furl.add_header('Referer', 'http://www.example2ref.org/dbget-bin/rest/?x=34324&y=3234324')
    furl.add_header('User-agent', 'Mozilla/3.0 AppleWebKit/535.1 (KHTML, like Gecko) Chrome/7.0.210 Safari/535.1')
    furl.add_header('Accept', 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8')
    furl.add_header('Accept-Encoding', 'gzip,deflate,sdch')
    furl.add_header('Accept-Language', 'en-US,en;q=0.8')
    furl.add_header('Origin', 'http://www.example.org/rest/assured/that')
    f = urllib2.urlopen(furl)
    print f.read(10000)

if __name__ == '__main__':
    main()
