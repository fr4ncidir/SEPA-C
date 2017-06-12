/*
 * secure_apis.c
 * 
 * Copyright 2017 Francesco Antoniazzi <francesco.antoniazzi@unibo.it>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

/**
 * @brief Example of code used to make a secure registration to SEPA
 * @file secure_apis.c
 * @author Francesco Antoniazzi <francesco.antoniazzi@unibo.it>
 * @date 3 jun 2017
 * @example
 */
 
#define SEPA_LOGGER_ERROR
#include <stdio.h>
#include "../sepa_secure.h"

int main(int argc, char **argv) {
	// compile with 
	// $ gcc ./examples/secure_apis.c sepa_utilities.c sepa_consumer.c sepa_secure.c jsmn.c -o secure_apis -lwebsockets -pthread -lcurl `pkg-config --cflags --libs glib-2.0`
	sClient authorizationData = _init_sClient();
	
	//registerClient("08:00:11:22:33:44:55:66:77","https://10.0.2.15:8443/oauth/register",&authorizationData);
	//fprintfSecureClientData(stdout,authorizationData);
	authorizationData.client_id = strdup("5b60a155-bada-4499-bc6f-26b4d37bc1ef");
	authorizationData.client_secret = strdup("40e18d77-421c-48ce-a44a-14da1238e923");
	tokenRequest(&authorizationData,"https://10.0.2.15:8443/oauth/token");
	return 0;
}