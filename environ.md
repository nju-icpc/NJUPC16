## Environment

评测机配置: Intel(R) Xeon(R) W-2125 CPU @ 4.00GHz, RAM 64GB, OS Ubuntu 18.04

### 编程语言

#### C

gcc (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0
编译命令：`gcc -Wall -std=c11 -ggdb -O2 -static -pipe -o "$DEST" "$@" -lm`

#### C++

g++ (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0
编译命令：`g++ -Wall -std=c++14 -ggdb -O2 -static -pipe -o "$DEST" "$@"`

#### Java

openjdk version "1.8.0_191"
OpenJDK Runtime Environment (build 1.8.0_191-8u191-b12-2ubuntu0.18.04.1-b12)
OpenJDK 64-Bit Server VM (build 25.191-b12, mixed mode)
编译命令：`javac -encoding UTF-8 -sourcepath . -d . "$@" 2> "$TMPFILE"`
执行命令：`java -Dfile.encoding=UTF-8 -XX:+UseSerialGC -Xss65536k -Xms1966080k -Xmx1966080k '$MAINCLASS' "\$@"`

#### Python 2

Python 2.7.13 (5.10.0+dfsg-3build2, Feb 06 2018, 18:37:50) [PyPy 5.10.0 with GCC 7.3.0]

编译命令：`python2 -m py_compile "$@"`
执行命令：`pypy "$MAINSOURCE" "\$@"`

已安装模块列表
```
BaseHTTPServer      _resource_build     formatter           quopri
Bastion             _resource_cffi      fpformat            random
CDROM               _scproxy            fractions           re
CGIHTTPServer       _sha                ftplib              readline
Canvas              _sha256             functools           repr
ConfigParser        _sha512             future_builtins     resource
Cookie              _socket             gc                  rexec
DLFCN               _sqlite3            gdbm                rfc822
DLFCN_default       _sqlite3_build      genericpath         rlcompleter
DLFCN_mips          _sqlite3_cffi       getopt              robotparser
Dialog              _sre                getpass             runpy
DocXMLRPCServer     _ssl                gettext             sched
FileDialog          _strptime           glob                select
FixTk               _struct             greenlet            sets
HTMLParser          _structseq          grp                 sgmllib
IN                  _subprocess         gzip                sha
IN_alpha            _sysconfigdata      hashlib             shelve
IN_default          _syslog_build       heapq               shlex
IN_hppa             _syslog_cffi        hmac                shutil
IN_mips             _testcapi           hotshot             signal
IN_sparc            _testing            htmlentitydefs      site
MimeWriter          _threading_local    htmllib             smtpd
Queue               _vmprof             httplib             smtplib
ScrolledText        _warnings           identity_dict       sndhdr
SimpleDialog        _weakref            idlelib             socket
SimpleHTTPServer    _weakrefset         ihooks              sqlite3
SimpleXMLRPCServer  abc                 imaplib             sre
SocketServer        aifc                imghdr              sre_compile
StringIO            antigravity         imp                 sre_constants
TYPES               anydbm              importlib           sre_parse
Tix                 argparse            imputil             ssl
Tkconstants         array               inspect             stackless
Tkdnd               ast                 io                  stat
Tkinter             asynchat            itertools           statvfs
UserDict            asyncore            json                string
UserList            atexit              keyword             stringold
UserString          audiodev            lib2to3             stringprep
_LWPCookieJar       audioop             linecache           struct
_MozillaCookieJar   base64              locale              subprocess
__builtin__         bdb                 logging             sunau
__future__          binascii            macpath             sunaudio
__pypy__            binhex              macurl2path         symbol
_abcoll             bisect              mailbox             symtable
_ast                bsddb               mailcap             sys
_audioop_build      bz2                 markupbase          sysconfig
_audioop_cffi       cPickle             marshal             syslog
_cffi_backend       cProfile            math                tabnanny
_codecs             cStringIO           md5                 tarfile
_codecs_cn          calendar            mhlib               telnetlib
_codecs_hk          cffi                mimetools           tempfile
_codecs_iso2022     cgi                 mimetypes           termios
_codecs_jp          cgitb               mimify              test
_codecs_kr          chunk               mmap                textwrap
_codecs_tw          cmath               modulefinder        this
_collections        cmd                 msilib              thread
_continuation       code                msvcrt              threading
_cppyy              codecs              multifile           time
_csv                codeop              multiprocessing     timeit
_ctypes             collections         mutex               tkColorChooser
_ctypes_test        colorsys            netrc               tkCommonDialog
_curses             commands            new                 tkFileDialog
_curses_build       compileall          nntplib             tkFont
_curses_cffi        compiler            ntpath              tkMessageBox
_curses_panel       contextlib          nturl2path          tkSimpleDialog
_elementtree        cookielib           numbers             toaiff
_ffi                copy                opcode              token
_file               copy_reg            operator            tokenize
_functools          cpyext              optparse            tputil
_gdbm_build         crypt               os                  trace
_gdbm_cffi          csv                 os2emxpath          traceback
_hashlib            ctypes              parser              ttk
_io                 ctypes_support      pdb                 tty
_jitlog             curses              pickle              turtle
_locale             datetime            pickletools         types
_lsprof             dbhash              pipes               unicodedata
_marshal            dbm                 pkgutil             unittest
_md5                decimal             platform            urllib
_minimal_curses     difflib             plistlib            urllib2
_multibytecodec     dircache            popen2              urlparse
_multiprocessing    dis                 poplib              user
_numpypy            distutils           posix               uu
_osx_support        doctest             posixfile           uuid
_pickle_support     dumbdbm             posixpath           warnings
_pwdgrp_build       dummy_thread        pprint              wave
_pwdgrp_cffi        dummy_threading     profile             weakref
_pyio               email               pstats              webbrowser
_pypy_interact      encodings           pty                 whichdb
_pypy_irc_topic     ensurepip           pwd                 wsgiref
_pypy_testcapi      errno               py_compile          xdrlib
_pypy_wait          exceptions          pyclbr              xml
_pypy_winbase_build faulthandler        pydoc               xmllib
_pypy_winbase_cffi  fcntl               pydoc_data          xmlrpclib
_pypyjson           filecmp             pyexpat             zipfile
_random             fileinput           pypyjit             zipimport
_rawffi             fnmatch             pyrepl              zlib
```

#### Python3

Python 3.5.3 (7.0.0+dfsg-2~ppa1~ubuntu18.04, Feb 09 2019, 07:25:02)
[PyPy 7.0.0 with GCC 7.3.0]

编译命令：`python3 -m py_compile "$@"`
执行命令：`pypy3 "$MAINSOURCE" "\$@"`

已安装模块列表
```
__exceptions__      _sqlite3_build      fileinput           pyrepl
__future__          _sqlite3_cffi       fnmatch             queue
__pypy__            _sre                formatter           quopri
_ast                _ssl                fractions           random
_audioop_build      _ssl_build          ftplib              re
_audioop_cffi       _stat               functools           readline
_bootlocale         _string             future_builtins     reprlib
_bz2                _strptime           gc                  resource
_cffi_backend       _struct             genericpath         rlcompleter
_codecs             _structseq          getopt              runpy
_codecs_cn          _sysconfigdata      getpass             sched
_codecs_hk          _syslog_build       gettext             select
_codecs_iso2022     _syslog_cffi        gi                  selectors
_codecs_jp          _testcapi           glob                shelve
_codecs_kr          _testing            greenlet            shlex
_codecs_tw          _testmultiphase     grp                 shutil
_collections        _thread             gzip                signal
_collections_abc    _threading_local    hashlib             site
_compat_pickle      _vmprof             heapq               smtpd
_compression        _warnings           hmac                smtplib
_continuation       _weakref            html                sndhdr
_cppyy              _weakrefset         http                socket
_crypt              _winapi             identity_dict       socketserver
_csv                abc                 idlelib             softwareproperties
_ctypes             aifc                imaplib             sqlite3
_ctypes_test        antigravity         imghdr              sre_compile
_curses             apt                 imp                 sre_constants
_curses_build       aptsources          importlib           sre_parse
_curses_cffi        argparse            inspect             ssl
_curses_cffi_check  array               io                  stackless
_curses_panel       ast                 ipaddress           stat
_dbm                asynchat            itertools           statistics
_decimal            asyncio             json                string
_decimal_build      asyncore            keyword             stringprep
_decimal_cffi       atexit              lib2to3             struct
_dummy_thread       audioop             linecache           subprocess
_ffi                base64              locale              sunau
_frozen_importlib   bdb                 logging             symbol
_functools          binascii            lsb_release         symtable
_gdbm               binhex              lzma                sys
_gdbm_build         bisect              macpath             sysconfig
_gdbm_cffi          builtins            macurl2path         syslog
_hashlib            bz2                 mailbox             tabnanny
_imp                cProfile            mailcap             tarfile
_io                 calendar            marshal             telnetlib
_jitlog             cffi                math                tempfile
_locale             cgi                 mimetypes           termios
_lsprof             cgitb               mmap                test
_lzma               chunk               modulefinder        textwrap
_lzma_build         cmath               msilib              this
_lzma_cffi          cmd                 msvcrt              threading
_markupbase         code                multiprocessing     time
_marshal            codecs              netrc               timeit
_md5                codeop              nntplib             tkinter
_minimal_curses     collections         ntpath              token
_multibytecodec     colorsys            nturl2path          tokenize
_multiprocessing    compileall          numbers             tputil
_operator           concurrent          opcode              trace
_osx_support        configparser        operator            traceback
_pickle_support     contextlib          optparse            tracemalloc
_posixsubprocess    copy                os                  tty
_pwdgrp_build       copyreg             parser              turtle
_pwdgrp_cffi        cpyext              pathlib             turtledemo
_pydecimal          crypt               pdb                 types
_pyio               csv                 pickle              typing
_pypy_interact      ctypes              pickletools         unicodedata
_pypy_irc_topic     ctypes_support      pipes               unittest
_pypy_openssl       curses              pkgutil             urllib
_pypy_testcapi      datetime            platform            uu
_pypy_wait          dbm                 plistlib            uuid
_pypy_winbase_build dbus                poplib              venv
_pypy_winbase_cffi  decimal             posix               warnings
_pypyjson           difflib             posixpath           wave
_random             dis                 pprint              weakref
_rawffi             distutils           profile             webbrowser
_resource_build     doctest             pstats              wsgiref
_resource_cffi      dummy_threading     pty                 xdrlib
_scproxy            email               pwd                 xml
_sha1               encodings           py_compile          xmlrpc
_sha256             ensurepip           pyclbr              zipapp
_sha512             enum                pydoc               zipfile
_signal             errno               pydoc_data          zipimport
_sitebuiltins       faulthandler        pyexpat             zlib
_socket             fcntl               pygtkcompat         
_sqlite3            filecmp             pypyjit             
```

### 编程工具

IntelliJ IDEA (Version TBD)
PyCharm (Version TBD)
CLion (Version TBD)
Code::Blocks (Version TBD)