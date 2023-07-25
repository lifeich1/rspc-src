import web

urls = (
    '/', 'index'
)

class index:
    def _hdrs(self):
        web.header('Access-Control-Allow-Origin', '*')
        web.header('Access-Control-Request-Method', 'POST,OPTIONS')
        #web.header('Access-Control-Request-Headers', 'cache-control,content-type,orgin,accept')
        web.header('Access-Control-Allow-Headers', '*')
        web.header('Access-Control-Allow-Age', '3600')
    def POST(self):
        self._hdrs()
        i = web.input()
        print(i.ns)
        a = i.ul.split('/')
        print(repr(a))
        fn = './leetcode/'+a[4]+'.txt'
        with open(fn, 'w') as fo:
            print(i.ns, file=fo)
        return 'ok'
    def OPTIONS(self):
        self._hdrs()
        return 'ok'

if __name__ == "__main__":
    app = web.application(urls, globals())
    app.run()
