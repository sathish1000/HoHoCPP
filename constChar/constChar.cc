/*
 * Copyright (c) 2009-2010, Oracle and/or its affiliates. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of Oracle nor the names of its contributors
 *   may be used to endorse or promote products derived from this software without
 *   specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <iostream>

using namespace std;

int main(int argc, char**argv) {
    // Prints welcome message...
    std::cout << "Welcome ..." << std::endl;

    // Prints arguments...
    if (argc > 1) {
        std::cout << std::endl << "Arguments:" << std::endl;
        for (int i = 1; i < argc; i++) {
            std::cout << i << ": " << argv[i] << std::endl;
        }
    }
       
    //pointer to const char.
    const char* str = "Hello";
    for (int i=0; i<5; i++){
        cout << str[i] << endl;
    }
    cout << "New" << endl;
    const char* str1 = "Goodb";
    str = str1;
    for (int i=0; i<5; i++){
        cout << str[i] << endl;
    }
    
    //cout << "New-1" << endl;
    //char s = "S";
    //str = &s;
    //cout << str << endl;

    cout << "New-2" << endl;    
    for (int i=0; i<5; i++){
    //    str[i] = 'a';
        cout << str[i] << endl;
    }
    
    //const pointer to char
    char a[] = "Hello";
    for (int i=0; i<5; i++){
        a[i] = 'a';
        cout << a[i] << endl;
    }
    
    cout << "Print a" << endl;
    cout << a << endl;    
    
    return 0;
}
