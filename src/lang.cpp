/*
 * SPDX-License-Identifier: GPL-3.0
 * Copyright © eastev <eastevrud31@gmail.com>
 */ 

/*
 * Simple-loc language info functions
 */

#include <lang.hpp>

loc::lang::lang(std::string& name, std::string& comment,
                    std::string& comment_block_open, 
                    std::string& comment_block_close)
{
    this->name = name;
    this->comment = comment;
    this->comment_block_open = comment_block_open;
    this->comment_block_close = comment_block_close;
    this->code = 0;
    this->files = 0;
}

std::string& loc::lang::get_name()
{
    return this->name;
}

void loc::lang::add_file()
{
    #ifndef __x86_64__
        if(this->files < UINT32_MAX)
        {
            this->files++;

            return;
        }
    #else
        if(this->files < UINT64_MAX)
        {
            this->files++;

            return;
        }
    #endif

    fprintf(stderr, "\033[0;31mERROR\033[0m: Too much files!\n\n");
    exit(-1);
}

void loc::lang::add_code(uint code)
{
    #ifndef __x86_64__
        if(this->code + code < UINT32_MAX)
        {
            this->code += code;

            return;
        }
    #else
        if(this->code + code < UINT64_MAX)
        {
            this->code += code;

            return;
        }
    #endif

    fprintf(stderr, "\033[0;31mERROR\033[0m: Too much code!\n\n");
    exit(-1);
}

std::string& loc::lang::get_comment()
{
    return this->comment;
}

std::string& loc::lang::get_comment_block_open()
{
    return this->comment_block_open;
}

std::string& loc::lang::get_comment_block_close()
{
    return this->comment_block_close;
}
