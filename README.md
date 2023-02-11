# minishell for 42cursus.

This project is about creating a simple shell, our own little bash. The goal is to learn about processes and files descriptors. We had to work as duo 
with @Rudyar to realise this project.

Minishell almost works the same as bash. It does not behaves exactly like bash does in some cases.

We had to implement redirections such as : <br>
◦ < <br>
◦ > <br>
◦ << <br>
◦ >> <br>

We also had to implement pipes and handle environment variables or signals such as ctrl-c, ctrl-d, ctrl-\\.

And finally, we had to recode the following builtins : <br>
◦ echo <br>
◦ cd <br>
◦ pwd <br>
◦ export <br>
◦ unset <br>
◦ env <br>
◦ exit <br>

### Our grade :mortar_board:
[![lleveque's 42 minishell Score](https://badge42.vercel.app/api/v2/clc6bxaur00060fmon220zhly/project/2553765)](https://github.com/JaeSeoKim/badge42)

### Usage :desktop_computer:

First:

    git clone https://github.com/lleveque42/minishell
    cd minishell
    
Then:
    
    make
