package neostar;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.HashMap;
import java.util.Iterator;
import java.util.TreeMap;

public class EnchantedBookRender {
    private String result = "";
    private HashMap<String, String> renders = new HashMap<>();
    private String json = "{\n" +
            "    \"namespace\": \"common\",\n" +
            "    \"screen_header_title_panel\": {\n" +
            "        \"type\": \"panel\",\n" +
            "        \"size\": [\n" +
            "            \"fill\",\n" +
            "            17\n" +
            "        ],\n" +
            "        \"$screen_header_title_visible|default\": true,\n" +
            "        \"controls\": [\n" +
            "            {\n" +
            "                \"store_header_title\": {\n" +
            "                    \"type\": \"label\",\n" +
            "                    \"size\": [\n" +
            "                        \"100%\",\n" +
            "                        17\n" +
            "                    ],\n" +
            "                    \"offset\": [\n" +
            "                        0,\n" +
            "                        3.5\n" +
            "                    ],\n" +
            "                    \"ignored\": \"(not $screen_header_title_visible)\",\n" +
            "                    \"anchor_from\": \"left_middle\",\n" +
            "                    \"anchor_to\": \"left_middle\",\n" +
            "                    \"text_alignment\": \"left\",\n" +
            "                    \"color\": \"$title_text_color\",\n" +
            "                    \"$screen_header_title|default\": \"#screen_header_title\",\n" +
            "                    \"$screen_header_title_binding_type|default\": \"none\",\n" +
            "                    \"text\": \" \",\n" +
            "                    \"bindings\": [\n" +
            "                        {\n" +
            "                            \"binding_type\": \"$screen_header_title_binding_type\",\n" +
            "                            \"binding_name\": \"$screen_header_title\",\n" +
            "                            \"binding_name_override\": \"$screen_header_title\"\n" +
            "                        }\n" +
            "                    ]\n" +
            "                }\n" +
            "            }\n" +
            "        ]\n" +
            "    },\n" +
            "    \"text_edit_box\": {\n" +
            "        \"type\": \"edit_box\",\n" +
            "        \"$focus_id|default\": \"\",\n" +
            "        \"$focus_override_down|default\": \"\",\n" +
            "        \"$focus_override_up|default\": \"\",\n" +
            "        \"$focus_override_left|default\": \"\",\n" +
            "        \"$focus_override_right|default\": \"\",\n" +
            "        \"focus_identifier\": \"$focus_id\",\n" +
            "        \"focus_change_down\": \"$focus_override_down\",\n" +
            "        \"focus_change_up\": \"$focus_override_up\",\n" +
            "        \"focus_change_left\": \"$focus_override_left\",\n" +
            "        \"focus_change_right\": \"$focus_override_right\",\n" +
            "        \"focus_enabled\": true,\n" +
            "        \"anchor_from\": \"center\",\n" +
            "        \"anchor_to\": \"center\",\n" +
            "        \"layer\": 1,\n" +
            "        \"enabled\": \"#enabled\",\n" +
            "        \"$text_box_name|default\": \"#text_box_name\",\n" +
            "        \"$text_box_enabled_binding_name|default\": \"#text_box_enabled\",\n" +
            "        \"$text_edit_box_enabled_binding_type|default\": \"global\",\n" +
            "        \"$text_edit_box_grid_collection_name|default\": \"\",\n" +
            "        \"$text_edit_clipping_panel_size|default\": [\n" +
            "            \"100%\",\n" +
            "            \"100%\"\n" +
            "        ],\n" +
            "        \"$text_edit_box_label_size|default\": [\n" +
            "            \"default\",\n" +
            "            \"default\"\n" +
            "        ],\n" +
            "        \"$text_edit_box_label_anchor_point|default\": \"right_middle\",\n" +
            "        \"$text_edit_box_label_min_size|default\": [\n" +
            "            \"100%\",\n" +
            "            0\n" +
            "        ],\n" +
            "        \"$text_edit_box_label_offset|default\": [\n" +
            "            0,\n" +
            "            0\n" +
            "        ],\n" +
            "        \"text_box_name\": \"$text_box_name\",\n" +
            "        \"text_edit_box_grid_collection_name\": \"$text_edit_box_grid_collection_name\",\n" +
            "        \"$deselectable_binding_type|default\": \"none\",\n" +
            "        \"$deselectable_binding_name|default\": \"#can_be_deselected\",\n" +
            "        \"$text_edit_box_focusable_binding_name|default\": \"#text_edit_box_focusable\",\n" +
            "        \"$text_edit_visible_binding_name|default\": \"#text_edit_box_visible\",\n" +
            "        \"$text_edit_visible_binding_collection_name|default\": \"\",\n" +
            "        \"$text_edit_visible_binding_type|default\": \"none\",\n" +
            "        \"$text_edit_type_name|default\": \"accessibility.textbox.tts.title\",\n" +
            "        \"$text_box_tts_header|default\": \"\",\n" +
            "        \"$tts_section_header|default\": \"\",\n" +
            "        \"tts_name\": \"$text_edit_type_name\",\n" +
            "        \"tts_control_header\": \"$text_box_tts_header\",\n" +
            "        \"tts_section_header\": \"$tts_section_header\",\n" +
            "        \"$tts_override_control_value|default\": \" \",\n" +
            "        \"tts_override_control_value\": \"$tts_override_control_value\",\n" +
            "        \"bindings\": [\n" +
            "            {\n" +
            "                \"binding_type\": \"$text_edit_box_enabled_binding_type\",\n" +
            "                \"binding_collection_name\": \"$text_edit_box_grid_collection_name\",\n" +
            "                \"binding_name\": \"$text_box_enabled_binding_name\",\n" +
            "                \"binding_name_override\": \"#enabled\"\n" +
            "            },\n" +
            "            {\n" +
            "                \"binding_type\": \"$deselectable_binding_type\",\n" +
            "                \"binding_name\": \"$deselectable_binding_name\",\n" +
            "                \"binding_name_override\": \"#can_be_deselected\"\n" +
            "            },\n" +
            "            {\n" +
            "                \"binding_type\": \"none\",\n" +
            "                \"binding_name\": \"$text_edit_box_focusable_binding_name\",\n" +
            "                \"binding_name_override\": \"#focus_enabled\"\n" +
            "            },\n" +
            "            {\n" +
            "                \"binding_name\": \"$text_edit_visible_binding_name\",\n" +
            "                \"binding_name_override\": \"#visible\",\n" +
            "                \"binding_type\": \"$text_edit_visible_binding_type\",\n" +
            "                \"binding_collection_name\": \"$text_edit_visible_binding_collection_name\"\n" +
            "            }\n" +
            "        ],\n" +
            "        \"locked_control\": \"locked\",\n" +
            "        \"default_control\": \"default\",\n" +
            "        \"hover_control\": \"hover\",\n" +
            "        \"pressed_control\": \"pressed\",\n" +
            "        \"max_length\": 14,\n" +
            "        \"$text_edit_box_text_type|default\": \"ExtendedASCII\",\n" +
            "        \"text_type\": \"$text_edit_box_text_type\",\n" +
            "        \"$virtual_keyboard_buffer_control|default\": \"\",\n" +
            "        \"virtual_keyboard_buffer_control\": \"$virtual_keyboard_buffer_control\",\n" +
            "        \"$text_edit_text_control|default\": \"display_text\",\n" +
            "        \"text_control\": \"$text_edit_text_control\",\n" +
            "        \"$place_holder_control\": \"common.text_edit_box_place_holder_label\",\n" +
            "        \"$text_background_default\": \"common.edit_box_indent\",\n" +
            "        \"$text_background_hover\": \"common.edit_box_indent_hover\",\n" +
            "        \"place_holder_control\": \"place_holder_control\",\n" +
            "        \"$text_edit_box_hovered_button_id|default\": \"button.text_edit_box_hovered\",\n" +
            "        \"$text_edit_box_clear_from_button_id|default\": \"button.menu_clear\",\n" +
            "        \"$text_edit_box_clear_to_button_id|default\": \"button.text_edit_box_clear\",\n" +
            "        \"$text_edit_box_clear_scope|default\": \"view\",\n" +
            "        \"$text_edit_box_selected_to_button_id|default\": \"button.text_edit_box_selected\",\n" +
            "        \"$text_edit_box_deselected_to_button_id|default\": \"button.text_edit_box_deselected\",\n" +
            "        \"button_mappings\": [\n" +
            "            {\n" +
            "                \"from_button_id\": \"button.menu_select\",\n" +
            "                \"to_button_id\": \"$text_edit_box_selected_to_button_id\",\n" +
            "                \"handle_select\": true,\n" +
            "                \"handle_deselect\": false,\n" +
            "                \"mapping_type\": \"pressed\"\n" +
            "            },\n" +
            "            {\n" +
            "                \"from_button_id\": \"button.menu_select\",\n" +
            "                \"to_button_id\": \"$text_edit_box_selected_to_button_id\",\n" +
            "                \"handle_select\": false,\n" +
            "                \"handle_deselect\": true,\n" +
            "                \"mapping_type\": \"global\",\n" +
            "                \"consume_event\": false\n" +
            "            },\n" +
            "            {\n" +
            "                \"from_button_id\": \"button.menu_ok\",\n" +
            "                \"to_button_id\": \"$text_edit_box_selected_to_button_id\",\n" +
            "                \"handle_select\": true,\n" +
            "                \"handle_deselect\": true,\n" +
            "                \"mapping_type\": \"pressed\"\n" +
            "            },\n" +
            "            {\n" +
            "                \"from_button_id\": \"button.menu_ok\",\n" +
            "                \"to_button_id\": \"$text_edit_box_selected_to_button_id\",\n" +
            "                \"handle_select\": false,\n" +
            "                \"handle_deselect\": true,\n" +
            "                \"mapping_type\": \"global\"\n" +
            "            },\n" +
            "            {\n" +
            "                \"from_button_id\": \"button.menu_cancel\",\n" +
            "                \"to_button_id\": \"$text_edit_box_deselected_to_button_id\",\n" +
            "                \"handle_select\": false,\n" +
            "                \"handle_deselect\": true,\n" +
            "                \"mapping_type\": \"global\"\n" +
            "            },\n" +
            "            {\n" +
            "                \"to_button_id\": \"$text_edit_box_hovered_button_id\",\n" +
            "                \"mapping_type\": \"pressed\"\n" +
            "            },\n" +
            "            {\n" +
            "                \"from_button_id\": \"$text_edit_box_clear_from_button_id\",\n" +
            "                \"to_button_id\": \"$text_edit_box_clear_to_button_id\",\n" +
            "                \"handle_select\": false,\n" +
            "                \"handle_deselect\": false,\n" +
            "                \"mapping_type\": \"focused\"\n" +
            "            }\n" +
            "        ],\n" +
            "        \"$shadow\": false,\n" +
            "        \"$font_size\": \"normal\",\n" +
            "        \"$color|default\": [\n" +
            "            1,\n" +
            "            1,\n" +
            "            1,\n" +
            "            1\n" +
            "        ],\n" +
            "        \"$alpha|default\": 1.0,\n" +
            "        \"$disabled_alpha|default\": 0.5,\n" +
            "        \"$text_offset|default\": [\n" +
            "            0,\n" +
            "            0\n" +
            "        ],\n" +
            "        \"$place_holder_text_hover_color|default\": \"$text_box_text_color\",\n" +
            "        \"place_holder_text_hover_color\": \"$place_holder_text_hover_color\",\n" +
            "        \"$text_clear_button_enabled|default\": false,\n" +
            "        \"$text_clear_button_size|default\": [\n" +
            "            15,\n" +
            "            15\n" +
            "        ],\n" +
            "        \"$text_clear_button_offset|default\": [\n" +
            "            0,\n" +
            "            0\n" +
            "        ],\n" +
            "        \"$magnifying_glass_enabled|default\": false,\n" +
            "        \"$magnifying_glass_size|default\": [\n" +
            "            10,\n" +
            "            10\n" +
            "        ],\n" +
            "        \"$magnifying_glass_offset|default\": [\n" +
            "            0,\n" +
            "            0\n" +
            "        ],\n" +
            "        \"controls\": [\n" +
            "            {\n" +
            "                \"anvil_text_input@anvil.anvil_text_input\": {}\n" +
            "            },\n" +
            "            {\n" +
            "                \"centering_panel\": {\n" +
            "                    \"type\": \"panel\",\n" +
            "                    \"size\": [\n" +
            "                        \"100% - 6px\",\n" +
            "                        \"100% - 4px\"\n" +
            "                    ],\n" +
            "                    \"controls\": [\n" +
            "                        {\n" +
            "                            \"clipper_panel\": {\n" +
            "                                \"type\": \"panel\",\n" +
            "                                \"size\": \"$text_edit_clipping_panel_size\",\n" +
            "                                \"anchor_from\": \"left_middle\",\n" +
            "                                \"anchor_to\": \"left_middle\",\n" +
            "                                \"offset\": \"$text_offset\",\n" +
            "                                \"clips_children\": true,\n" +
            "                                \"$disabled_color|default\": \"$color\",\n" +
            "                                \"controls\": [\n" +
            "                                    {\n" +
            "                                        \"$text_edit_text_control@common.text_edit_box_label\": {\n" +
            "                                            \"layer\": 1,\n" +
            "                                            \"size\": \"$text_edit_box_label_size\",\n" +
            "                                            \"offset\": \"$text_edit_box_label_offset\",\n" +
            "                                            \"min_size\": \"$text_edit_box_label_min_size\",\n" +
            "                                            \"anchor_from\": \"$text_edit_box_label_anchor_point\",\n" +
            "                                            \"anchor_to\": \"$text_edit_box_label_anchor_point\",\n" +
            "                                            \"font_size\": \"$font_size\",\n" +
            "                                            \"$text_alpha|default\": \"$alpha\",\n" +
            "                                            \"$locked_text_alpha|default\": \"$disabled_alpha\",\n" +
            "                                            \"$locked_color|default\": \"$disabled_color\"\n" +
            "                                        }\n" +
            "                                    },\n" +
            "                                    {\n" +
            "                                        \"magnifying_glass@common.text_magnifying_glass_image\": {\n" +
            "                                            \"anchor_from\": \"left_middle\",\n" +
            "                                            \"anchor_to\": \"left_middle\",\n" +
            "                                            \"visible\": \"$magnifying_glass_enabled\",\n" +
            "                                            \"size\": \"$magnifying_glass_size\",\n" +
            "                                            \"offset\": \"$magnifying_glass_offset\"\n" +
            "                                        }\n" +
            "                                    },\n" +
            "                                    {\n" +
            "                                        \"clear_text_button_panel\": {\n" +
            "                                            \"type\": \"panel\",\n" +
            "                                            \"size\": [\n" +
            "                                                \"100%\",\n" +
            "                                                \"100%\"\n" +
            "                                            ],\n" +
            "                                            \"visible\": \"$text_clear_button_enabled\",\n" +
            "                                            \"controls\": [\n" +
            "                                                {\n" +
            "                                                    \"clear_text_button@common.clear_text_button\": {\n" +
            "                                                        \"anchor_from\": \"right_middle\",\n" +
            "                                                        \"anchor_to\": \"right_middle\",\n" +
            "                                                        \"size\": \"$text_clear_button_size\",\n" +
            "                                                        \"offset\": \"$text_clear_button_offset\",\n" +
            "                                                        \"bindings\": [\n" +
            "                                                            {\n" +
            "                                                                \"binding_type\": \"global\",\n" +
            "                                                                \"binding_name\": \"#show_clear_text_button\",\n" +
            "                                                                \"binding_name_override\": \"#visible\"\n" +
            "                                                            }\n" +
            "                                                        ]\n" +
            "                                                    }\n" +
            "                                                }\n" +
            "                                            ]\n" +
            "                                        }\n" +
            "                                    },\n" +
            "                                    {\n" +
            "                                        \"visibility_panel\": {\n" +
            "                                            \"type\": \"panel\",\n" +
            "                                            \"$placeholder_label_size|default\": \"$text_edit_box_label_size\",\n" +
            "                                            \"controls\": [\n" +
            "                                                {\n" +
            "                                                    \"place_holder_control@$place_holder_control\": {\n" +
            "                                                        \"layer\": 1,\n" +
            "                                                        \"size\": \"$placeholder_label_size\",\n" +
            "                                                        \"offset\": \"$text_edit_box_label_offset\",\n" +
            "                                                        \"min_size\": \"$text_edit_box_label_min_size\",\n" +
            "                                                        \"anchor_from\": \"$text_edit_box_label_anchor_point\",\n" +
            "                                                        \"anchor_to\": \"$text_edit_box_label_anchor_point\",\n" +
            "                                                        \"$text_alpha|default\": \"$alpha\",\n" +
            "                                                        \"$locked_text_alpha|default\": \"$disabled_alpha\",\n" +
            "                                                        \"$locked_color|default\": \"$disabled_color\"\n" +
            "                                                    }\n" +
            "                                                }\n" +
            "                                            ],\n" +
            "                                            \"bindings\": [\n" +
            "                                                {\n" +
            "                                                    \"binding_type\": \"view\",\n" +
            "                                                    \"source_control_name\": \"$text_edit_text_control\",\n" +
            "                                                    \"source_property_name\": \"(#item_name = '')\",\n" +
            "                                                    \"target_property_name\": \"#visible\",\n" +
            "                                                    \"resolve_sibling_scope\": true\n" +
            "                                                }\n" +
            "                                            ]\n" +
            "                                        }\n" +
            "                                    }\n" +
            "                                ]\n" +
            "                            }\n" +
            "                        }\n" +
            "                    ]\n" +
            "                }\n" +
            "            },\n" +
            "            {\n" +
            "                \"locked\": {\n" +
            "                    \"type\": \"panel\",\n" +
            "                    \"$disabled_color|default\": \"$color\",\n" +
            "                    \"controls\": [\n" +
            "                        {\n" +
            "                            \"edit_box_indent@$text_background_default\": {\n" +
            "                                \"$color\": \"$disabled_color\",\n" +
            "                                \"$alpha\": \"$disabled_alpha\"\n" +
            "                            }\n" +
            "                        }\n" +
            "                    ]\n" +
            "                }\n" +
            "            },\n" +
            "            {\n" +
            "                \"default@$text_background_default\": {}\n" +
            "            },\n" +
            "            {\n" +
            "                \"hover@$text_background_hover\": {}\n" +
            "            },\n" +
            "            {\n" +
            "                \"pressed@$text_background_hover\": {}\n" +
            "            }\n" +
            "        ]\n" +
            "    },\n" +
            "    \"base_screen\": {\n" +
            "        \"low_frequency_rendering\": true,\n" +
            "        \"cache_screen\": true\n" +
            "    },\n" +
            "    \"flying_item_renderer\": {\n" +
            "        \"property_bag\": {\n" +
            "            \"#flying_item_renderer\": false\n" +
            "        }\n" +
            "    },\n" +
            "    \"container_item\": {\n" +
            "        \"$item_renderer|default\": \"common.custom_item_renderer\"\n" +
            "    },\n" +
            "    \"custom_item_renderer\": {\n" +
            "        \"type\": \"panel\",\n" +
            "        \"$ignore_enchanted_book_custom_renderer|default\": false,\n" +
            "        \"controls\": [\n" +
            "            {\n" +
            "                \"item_renderer@common.item_renderer\": {}\n" +
            "            },\n" +
            "            {\n" +
            "                \"enchanted_book_default_renderer@common.enchanted_book_default_renderer\": {}\n" +
            "            }";
    private String parentPath;

    private String and(String str1, String str2) {
        if (str1.isEmpty()) {
            return str2;
        } else {
            return "(" + str1 + " and " + str2 + ")";
        }
    }

    public void add(HashMap<String, String> renders) {
        TreeMap<String, String> treeMap = new TreeMap<>(renders);
        Iterator<String> iterator0 = treeMap.keySet().iterator();
        this.renders.putAll(renders);
        while (iterator0.hasNext()){
            String key = iterator0.next();
            json+=",\n" +
                    "            {\n" +
                    "                \"enchanted_book_"+key+"_renderer@common.enchanted_book_"+key+"_renderer\": {}\n" +
                    "            }\n";
        }
        json+="],\n" +
                "        \"bindings\": []\n" +
                "    },\n";
        json += "\"item_renderer\": {\n" +
                "        \"type\": \"custom\",\n" +
                "        \"renderer\": \"inventory_item_renderer\",\n" +
                "        \"layer\": 0,\n" +
                "        \"size\": \"$item_renderer_size\",\n" +
                "        \"$common_inv|default\": true";
        Iterator<String> iterator1 = treeMap.keySet().iterator();
        while (iterator1.hasNext()) {
            String key = iterator1.next();
            json+=",\n" +
                    "        \"$ignore_enchanted_book_"+key+"_renderer|default\": true";
        }
        json += ",\n" +
                "        \"$item_renderer_size|default\": [\n" +
                "            16,\n" +
                "            16\n" +
                "        ],\n" +
                "        \"$item_collection_name|default\": \"none\",\n" +
                "        \"$detect_binding|default\": \"#hover_text\",\n" +
                "        \"$item_renderer_binding_condition|default\": \"none\",\n" +
                "        \"modifications\": [\n" +
                "            {\n" +
                "                \"array_name\": \"bindings\",\n" +
                "                \"operation\": \"insert_front\",\n" +
                "                \"value\": [\n" +
                "                    {\n" +
                "                        \"ignored\": \"$common_inv\",\n" +
                "                        \"binding_type\": \"collection_details\"\n" +
                "                    },\n" +
                "                    {\n" +
                "                        \"binding_name\": \"$detect_binding\",\n" +
                "                        \"binding_type\": \"collection\",\n" +
                "                        \"binding_collection_name\": \"$item_collection_name\"\n" +
                "                    },\n" +
                "                    {\n" +
                "                        \"binding_type\": \"view\",\n" +
                "                        \"source_property_name\": \"((($detect_binding-'附魔书')=$detect_binding) or (not(($detect_binding-'潜影盒')=$detect_binding)))\",\n" +
                "                        \"target_property_name\": \"#visible\"\n" +
                "                    }\n" +
                "                ]\n" +
                "            }\n" +
                "        ]\n" +
                "    },\n" +
                "    \"enchanted_book_default_renderer\": {\n" +
                "        \"$common_inv|default\": true,\n" +
                "        \"$detect_binding|default\": \"#hover_text\",\n" +
                "        \"$collection_type|default\": \"collection\",\n" +
                "        \"$item_renderer_offset|default\": [\n" +
                "            0,\n" +
                "            0\n" +
                "        ],\n" +
                "        \"$item_renderer_size|default\": [\n" +
                "            16,\n" +
                "            16\n" +
                "        ],\n" +
                "        \"ignored\": \"$ignore_enchanted_book_default_renderer\",\n" +
                "        \"size\": \"$item_renderer_size\",\n" +
                "        \"offset\": \"$item_renderer_offset\",\n" +
                "        \"anchor_to\": \"center\",\n" +
                "        \"anchor_from\": \"center\",\n" +
                "        \"layer\": 1,\n" +
                "        \"type\": \"image\",\n" +
                "        \"$item_collection_name|default\": \"none\",\n" +
                "        \"$det|default\": \"\",\n" +
                "        \"texture\": \"textures/items/enchanted_book/eb00\",\n" +
                "        \"bindings\": [\n" +
                "            {\n" +
                "                \"ignored\": \"$common_inv\",\n" +
                "                \"binding_type\": \"collection_details\"\n" +
                "            },\n" +
                "            {\n" +
                "                \"binding_name\": \"$detect_binding\",\n" +
                "                \"binding_type\": \"$collection_type\",\n" +
                "                \"binding_collection_name\": \"$item_collection_name\"\n" +
                "            },\n" +
                "            {\n" +
                "                \"binding_type\": \"view\",\n" +
                "                \"source_property_name\": \"((not(($detect_binding-'附魔书')=$detect_binding)) and (($detect_binding-'潜影盒')=$detect_binding)))\",\n" +
                "                \"target_property_name\": \"#visible\"\n" +
                "            }\n" +
                "        ]\n" +
                "    }";
        Iterator<String> iterator2 = treeMap.keySet().iterator();
        while (iterator2.hasNext()) {
            String key = iterator2.next();
            json = json + ",\n    \"enchanted_book_" + key + "_renderer\": {\n" +
                    "        \"$common_inv|default\": true,\n" +
                    "        \"$detect_binding|default\": \"#hover_text\",\n" +
                    "        \"$collection_type|default\": \"collection\",\n" +
                    "        \"$ignore_enchanted_book_custom_renderer|default\": true,\n" +
                    "        \"$ignore_enchanted_book_"+key+"_renderer|default\": false,\n" +
                    "        \"$item_renderer_offset|default\": [\n" +
                    "            0,\n" +
                    "            0\n" +
                    "        ],\n" +
                    "        \"$item_renderer_size|default\": [\n" +
                    "            16,\n" +
                    "            16\n" +
                    "        ],\n" +
                    "        \"ignored\": \"$ignore_enchanted_book_" +
                    key + "_renderer\",\n" +
                    "        \"size\": \"$item_renderer_size\",\n" +
                    "        \"offset\": \"$item_renderer_offset\",\n" +
                    "        \"anchor_to\": \"center\",\n" +
                    "        \"anchor_from\": \"center\",\n" +
                    "        \"layer\": 1,\n" +
                    "        \"type\": \"image\",\n" +
                    "        \"$item_collection_name|default\": \"none\",\n" +
                    "        \"$det|default\": \"\",\n" +
                    "        \"texture\": \"" +
                    parentPath + key + "\",\n" +
                    "        \"bindings\": [\n" +
                    "            {\n" +
                    "                \"ignored\": \"$common_inv\",\n" +
                    "                \"binding_type\": \"collection_details\"\n" +
                    "            },\n" +
                    "            {\n" +
                    "                \"binding_name\": \"$detect_binding\",\n" +
                    "                \"binding_type\": \"$collection_type\",\n" +
                    "                \"binding_collection_name\": \"$item_collection_name\"\n" +
                    "            },\n" +
                    "            {\n" +
                    "                \"binding_type\": \"view\",\n" +
                    "                \"source_property_name\": \"((not(($detect_binding-'" +
                    treeMap.get(key) + "')=$detect_binding)) and not((($detect_binding-'附魔书')=$detect_binding)))\",\n" +
                    "                \"target_property_name\": \"#visible\"\n" +
                    "            }\n" +
                    "        ]\n" +
                    "    }";
        }
        json += "\n}";
        result = json;
    }

    public void setParentPath(String parentPath) {
        this.parentPath = parentPath;
    }

    public String getJson() {
        return result;
    }

    public void outPutJson() {
        File file = new File("ui_common.json");
        try {
            FileWriter fileWriter = new FileWriter(file);
            BufferedWriter out = new BufferedWriter(fileWriter);
            out.write(result);
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void clear() {
        renders.clear();
    }

    public void remove(String key) {
        renders.remove(key);
    }

    public void remove(String key, String name) {
        renders.remove(key, name);
    }
}
