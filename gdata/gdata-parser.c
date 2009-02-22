/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 8; tab-width: 8 -*- */
/*
 * GData Client
 * Copyright (C) Philip Withnall 2009 <philip@tecnocode.co.uk>
 * 
 * GData Client is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * GData Client is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GData Client.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <config.h>
#include <glib.h>
#include <glib/gi18n-lib.h>

#include "gdata-service.h"
#include "gdata-parser.h"

GQuark
gdata_parser_error_quark (void)
{
	return g_quark_from_static_string ("gdata-parser-error-quark");
}

gboolean
gdata_parser_error_required_content_missing (const gchar *element_name, GError **error)
{
	g_set_error (error, GDATA_SERVICE_ERROR, GDATA_SERVICE_ERROR_PROTOCOL_ERROR,
		     _("A <%s> element was missing required content."),
		     element_name);
	return FALSE;
}

/* TODO: parameters are in the wrong order */
gboolean
gdata_parser_error_not_iso8601_format (const gchar *parent_element_name, const gchar *element_name, const gchar *actual_value, GError **error)
{
	g_set_error (error, GDATA_SERVICE_ERROR, GDATA_SERVICE_ERROR_PROTOCOL_ERROR,
		     _("A <%s>'s <%s> element (\"%s\") was not in ISO8601 format."),
		     parent_element_name, element_name, actual_value);
	return FALSE;
}

gboolean
gdata_parser_error_unhandled_element (const gchar *element_namespace, const gchar *element_name, const gchar *parent_element_name, GError **error)
{
	g_set_error (error, GDATA_PARSER_ERROR, GDATA_PARSER_ERROR_UNHANDLED_XML_ELEMENT,
		     _("Unhandled <%s:%s> element as a child of <%s>."),
		     element_namespace, element_name, parent_element_name);
	return FALSE;
}

gboolean
gdata_parser_error_unknown_property_value (const gchar *element_name, const gchar *property_name, const gchar *actual_value, GError **error)
{
	g_set_error (error, GDATA_SERVICE_ERROR, GDATA_SERVICE_ERROR_PROTOCOL_ERROR,
		     _("Unknown value \"%s\" of a <%s> @%s property."),
		     actual_value, element_name, property_name);
	return FALSE;
}

gboolean
gdata_parser_error_required_property_missing (const gchar *element_name, const gchar *property_name, GError **error)
{
	g_set_error (error, GDATA_SERVICE_ERROR, GDATA_SERVICE_ERROR_PROTOCOL_ERROR,
		     _("A required @%s property of a <%s> was not present."),
		     property_name, element_name);
	return FALSE;
}

gboolean
gdata_parser_error_required_element_missing (const gchar *element_name, const gchar *parent_element_name, GError **error)
{
	g_set_error (error, GDATA_SERVICE_ERROR, GDATA_SERVICE_ERROR_PROTOCOL_ERROR,
		     _("A required <%s> element as a child of <%s> was not present."),
		     element_name, parent_element_name);
	return FALSE;
}

gboolean
gdata_parser_error_duplicate_element (const gchar *element_name, const gchar *parent_element_name, GError **error)
{
	g_set_error (error, GDATA_SERVICE_ERROR, GDATA_SERVICE_ERROR_PROTOCOL_ERROR,
		     _("A <%s> element as a child of <%s> was duplicated."),
		     element_name, parent_element_name);
	return FALSE;
}