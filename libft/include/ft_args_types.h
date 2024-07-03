/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_types.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 23:42:58 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/03 18:01:45 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARGS_TYPES_H
# define FT_ARGS_TYPES_H

# define ARG_MASK_ATYPE ~0x3
# define ARG_MASK_ANY_ARG 0x1

/// @brief Enum to define the type of the option
/// @details The type of the option is defined by the flags that are set in the
/// t_opt structure. The flags are defined in the enum e_opt_type.
/// The flags are defined as follows:
/// - OPT_ARG: The option has an argument
/// - OPT_EQSIGN: The option has an argument and the argument is separated by an
/// equal sign '=' (e.g. --option=arg). If the flag is not set, the argument is
/// considered to be in the next argument (e.g. --option arg).
/// - OPT_OTHER: The argument of the option is of another custom type (e.g. a
/// structure or an array or file with a custom extension etc.) 
/// - OPT_INT: The argument of the option is an integer
/// - OPT_STRING: The argument of the option is a string
/// - OPT_BOOL: The argument of the option is a boolean (0 | 1 | true | false)
/// - OPT_FLOAT: The argument of the option is a float
/// - OPT_LONG: The argument of the option is a long
/// - OPT_DOUBLE: The argument of the option is a double
/// - OPT_ALPHANUM: The argument of the option is an alphanumeric string
/// - OPT_HEX: The argument of the option is a hexadecimal number
/// - OPT_OCT: The argument of the option is an octal number
/// @details The flags can be combined with the bitwise OR operator '|'.
/// @details The flags OPT_INT, OPT_STRING, OPT_BOOL, OPT_FLOAT, OPT_LONG,
/// OPT_DOUBLE, OPT_ALPHANUM, OPT_HEX, OPT_OCT are the standard types that can
/// be used to define the type of the argument of the option. The flag OPT_OTHER
/// is a custom type that can be used to define the type of the argument of the
/// option. The custom type can be defined by setting a custom checker with the
/// function set_custom_checker. The custom checker will be called to check the
/// argument of the option. The custom checker should return 0 if the argument
/// is valid and -1 if the argument is invalid. The custom checker should be
/// defined as follows:
/// @code
/// int	custom_checker(char *arg)
/// {
/// // check the argument
/// return (0 or -1);
/// }
/// @endcode
/// @see: set_custom_checker to set a custom checker for the argument of type
/// OPT_OTHER.
/// @warning: System limitations: Currently you cannot set an option which uses
/// more than one argument. You can set an option which uses a custom type
/// (OPT_OTHER) but the custom type should be defined as a single argument.
/// @see: t_opt
/// @see: set_custom_checker
///
typedef enum e_opt_type
{
	OPT_ARG = 1,
	OPT_EQSIGN = 2,
	OPT_OTHER = 4,
	OPT_INT = 8,
	OPT_STRING = 12,
	OPT_BOOL = 16,
	OPT_FLOAT = 20,
	OPT_LONG = 24,
	OPT_DOUBLE = 28,
	OPT_ALPHANUM = 32,
	OPT_HEX = 36,
	OPT_OCT = 40,
}				t_opt_type;

/// @brief Structure to define the options
/// @param opt_long_name: The long name of the option "name" (without the "--")
/// @param opt_short_name: The short name of the option 'n' (without the "-")
/// @param opt_type: The type of the option
/// @param opt_func: The function to call when the option is found casted as 
/// void * and later casted depending on the flags
///	@details An example of how to use the structure:
///	@code
/// #include "ft_args.h"
/// #include "ft_args_types.h"
/// #include "ft_string.h"
/// #include <stdio.h>
/// 
/// typedef struct s_control {
/// 	int n;
/// 	char *name;
/// 	float f;
/// }	t_control;
/// 
/// void set_n(void *control_struct, char *arg) {
/// 	printf("set_n\n");
/// 	((t_control *)control_struct)->n = ft_atoi(arg);
/// }
/// void set_name(void *control_struct, char *arg) {
/// 	printf("set_name\n");
/// 	((t_control *)control_struct)->name = arg;
/// }
/// void set_f(void *control_struct, char *arg) {
/// 	printf("set_f\n");
/// 	((t_control *)control_struct)->f = ft_atof(arg);
/// }
/// int main(int argc, char **argv) {
/// 	t_control control;
/// 	t_opt opt_list[] = {
/// 	{"nbr", 'n', set_n,  OPT_INT | OPT_EQSIGN},
/// 	{"name", 'a', set_name, OPT_STRING | OPT_EQSIGN},
/// 	{"float", 'f', set_f, OPT_FLOAT | OPT_EQSIGN},
/// 	{NULL, 0, NULL, 0}
/// 	};
/// 
/// 	ft_bzero(&control, sizeof(t_control));
/// 	ft_set_opt_list(opt_list);
/// 	ft_parse_args(argv, &control);
/// 	printf("n = %d\nname = %s\nf = %f\n", control.n, control.name, 
/// 	control.f);
/// 	return (0);
/// }
/// @endcode
/// @details The previous code will parse the arguments and set the values of 
/// the control structure according to the options found in the arguments.
/// @details the function set_n will be called when the option --nbr or -n is
/// found in the arguments, and will be casted as a void (*) (void *, char *).
///
typedef struct s_opt
{
	char		*long_name;
	char		short_name;
	void		*func;
	t_opt_type	type;
}				t_opt;

#endif
