<p align="center">
  <img src="https://i.ibb.co/0f8RbX2/Capture-d-cran-2024-03-18-231128.png" />
</p>

libtest is a command-line utility designed to test the functions provided in the libft library.
With no TEST specified, standard tests are applied to the function.
It includes options to test mandatory and bonus functions, display available functions, and provide version information.

## Features
- Check norme errors
- Check forbidden functions
- Check memory leaks

## Installation
- Ensure you have a Makefile in your libft containing the targets `all`, `re`, `bonus`, `clean`, and `fclean`.
- Clone the repository into your libft folder using the following command:
```bash
git clone git@github.com:FonWasH/libtest.git
```
Make sure your environment is properly configured before proceeding with the installation steps.

## Dependencies
- Norminette https://github.com/42School/norminette
- bc > `sudo apt install bc`

## Usage
```bash
  libtest [OPTION/FUNCTION]... [TEST]...

  -a, --all         test all functions; TEST is unavailable
  -m, --mandatory   test mandatory functions; TEST is unavailable
  -b, --bonus       test bonus functions; TEST is unavailable
  -s, --show        display all available functions
  -h, --help        display help and exit
  -v, --version     output version information and exit
```
  
## Examples
- `libtest ft_atoi 42`	Test the ft_atoi function with the input "42".
- `libtest -m`			Test all mandatory functions with standard tests.
