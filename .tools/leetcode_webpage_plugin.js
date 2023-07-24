// ==UserScript==
// @name         leetcode sync ranking
// @namespace    http://tampermonkey.net/
// @version      0.1
// @description  try to take over the world!
// @author       You
// @match        https://leetcode.cn/contest/*/ranking/
// @icon         https://www.google.com/s2/favicons?sz=64&domain=leetcode.cn
// @grant        none
// @connect      localhost
// ==/UserScript==

(function() {
    'use strict';
    console.log('lsr 0.2');
    var btn = null;
    function myemit() {
        let ns = document.getElementsByClassName('success')[0].innerText;
        //alert(ns);
        let xmlobj = new XMLHttpRequest();
        xmlobj.open("POST", "http://localhost:13013", true);
        xmlobj.setRequestHeader("cache-control","no-cache");
        xmlobj.setRequestHeader('Content-type', 'application/x-www-form-urlencoded')
        xmlobj.send('ns='+ns+'&ul='+document.URL);
        xmlobj.onload = function(e) {
            if (xmlobj.readyState == 1) {
                btn.innerHTML = ".";
            } else if (xmlobj.readyState == 2) {
                btn.innerHTML = "..";
            } else if (xmlobj.readyState == 3) {
                btn.innerHTML = "...";
            } else {
                btn.innerHTML = "OK";
            }
            console.log('lsr onload', e);
        };
        xmlobj.ontimeout = function() {
            btn.innerHTML = "TLE";
        };
        xmlobj.onerror = function(e) {
            btn.innerHTML = "RE";
            console.log('lsr onerror', e);
        };
    }
    function addButton(text, onclick, cssObj) {
        cssObj = cssObj || {position: 'absolute', bottom: '7%', left:'4%', 'z-index': 3}
        let button = document.createElement('button'), btnStyle = button.style
        document.body.appendChild(button)
        button.innerHTML = text
        button.onclick = onclick
        btnStyle.position = 'absolute'
        Object.keys(cssObj).forEach(key => btnStyle[key] = cssObj[key])
        return button
    }
    btn = addButton(
        "Emit", myemit, false
    );
})();
