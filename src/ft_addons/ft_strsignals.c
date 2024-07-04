/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsignals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:02:26 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/04 12:15:06 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

const char	*ft_strsignal(int sig)
{
	const char	*signals[] = {
		"Unknown signal", "Hangup", "Interrupt", "Quit", "Illegal instruction",
		"Trace/breakpoint trap", "Aborted", "Bus error",
		"Floating point exception", "Killed", "User defined signal 1",
		"Segmentation fault", "User defined signal 2", "Broken pipe",
		"Alarm clock", "Terminated", "Stack fault", "Child exited",
		"Continued", "Stopped (signal)", "Stopped", "Stopped (tty input)",
		"Stopped (tty output)", "Urgent I/O condition",
		"CPU time limit exceeded", "File size limit exceeded",
		"Virtual timer expired", "Profiling timer expired", "Window changed",
		"I/O possible", "Power failure", "Bad system call",
		"Unknown signal 32", "Unknown signal 33",
	};
	const char	*real_time_str = "Real-time signal";

	if (sig >= 1 && sig <= 33)
		return (signals[sig]);
	else if (sig >= 34 && sig <= 64)
		return (real_time_str);
	else
		return (signals[0]);
}
