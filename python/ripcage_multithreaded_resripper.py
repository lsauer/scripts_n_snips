#-------------------------------------------------------------------------------
# Name:        Ripcage
# Purpose:     Multithreaded ripping of web-resources e.g. KEGG mol files for conversion to Inchis
#
# Author:      Lo Sauer
# Note:        Please read the fair use policy (http://en.wikipedia.org/wiki/Fair_use) 
#              and consider whether it applies to your instance of resource ripping.
#              Script uses 'workerpool': http://code.google.com/p/workerpool/downloads/list
#
# Created:     12.09.2011
# Licence:     none, public domain
#-------------------------------------------------------------------------------
#!/usr/bin/env python

def main():
    import urllib
    import os
    import workerpool
    import urllib

    # Make a pool,with n workers
    pool = workerpool.WorkerPool(size=2)

    # Setup for the worker pool
    link = 'http://www.genome.jp/dbget-bin/www_bget?-f+m+compound+C' #00001 to ca....#16501
    startindex = 158
    maxindex = 16500
    savepath = 'C:/Chemlib/'
    fname = 'keggcmpd_'
    fext = '.mol'
    urls = [link+ `(i+1)`.zfill(5) for i in range (startindex,maxindex)]
    saveto = [savepath+fname+ `(i+1)`.zfill(5)+fext for i in range (startindex, maxindex)]

    # Map the function + params to the workers
    pool.map(urllib.urlretrieve, urls, saveto)
    pool.map(inchi, saveto)

    # signal termination to all threads
    pool.shutdown()
    #wait for job completion
    pool.wait()

def inchi(fname):
    import os
    from subprocess import call

    savepath = os.path.dirname(fname)
    os.popen(savepath+'/inchi-1.exe '+fname+' '+fname+'.inchi')

if __name__ == '__main__':
    main()
