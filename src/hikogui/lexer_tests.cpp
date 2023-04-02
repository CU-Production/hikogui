// Copyright Take Vos 2023.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at https://www.boost.org/LICENSE_1_0.txt)

#include "lexer.hpp"
#include <gtest/gtest.h>

TEST(lexer, integer_literal)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("42");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::integer, "42", 0));
    ++it;
    ASSERT_EQ(it, std::default_sentinel);
}

TEST(lexer, integer_literal_sigma)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("42∑");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::integer, "42", 0));
    ++it;
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::other, "∑", 2));
    ++it;
    ASSERT_EQ(it, std::default_sentinel);
}


TEST(lexer, integer_literal_digit_separator)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("4'2");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::integer, "42", 0));
    ++it;
    ASSERT_EQ(it, std::default_sentinel);
}

TEST(lexer, leading_zero_integer_literal)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("042");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::integer, "042", 0));
    ++it;
    ASSERT_EQ(it, std::default_sentinel);
}

TEST(lexer, leading_zero_integer_literal_invalid_digit1)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("084");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::error_invalid_digit, "0", 0));
}

TEST(lexer, leading_zero_integer_literal_invalid_digit2)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("048");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::error_invalid_digit, "04", 0));
}

TEST(lexer, hex_integer_literal1)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("0x4f");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::integer, "0x4f", 0));
    ++it;
    ASSERT_EQ(it, std::default_sentinel);
}

TEST(lexer, hex_integer_literal2)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("0X4f");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::integer, "0X4f", 0));
    ++it;
    ASSERT_EQ(it, std::default_sentinel);
}

TEST(lexer, hex_integer_literal_sigma)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("0X4f∑");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::integer, "0X4f", 0));
    ++it;
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::other, "∑", 4));
    ++it;
    ASSERT_EQ(it, std::default_sentinel);
}


TEST(lexer, dec_integer_literal1)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("0d42");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::integer, "0d42", 0));
    ++it;
    ASSERT_EQ(it, std::default_sentinel);
}

TEST(lexer, dec_integer_literal2)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("0D42");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::integer, "0D42", 0));
    ++it;
    ASSERT_EQ(it, std::default_sentinel);
}

TEST(lexer, oct_integer_literal1)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("0o42");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::integer, "0o42", 0));
    ++it;
    ASSERT_EQ(it, std::default_sentinel);
}

TEST(lexer, oct_integer_literal2)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("0O42");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::integer, "0O42", 0));
    ++it;
    ASSERT_EQ(it, std::default_sentinel);
}

TEST(lexer, oct_integer_literal_invalid_digit)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("0O82");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::error_invalid_digit, "0O", 0));
}

TEST(lexer, bin_integer_literal1)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("0b0101");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::integer, "0b0101", 0));
    ++it;
    ASSERT_EQ(it, std::default_sentinel);
}

TEST(lexer, bin_integer_literal2)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("0B0101");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::integer, "0B0101", 0));
    ++it;
    ASSERT_EQ(it, std::default_sentinel);
}

TEST(lexer, bin_integer_literal_invalid_digit)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("0B0201");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::error_invalid_digit, "0B0", 0));
}

TEST(lexer, float_literal)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("4.2");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::real, "4.2", 0));
    ++it;
    ASSERT_EQ(it, std::default_sentinel);
}

TEST(lexer, float_literal_only_fractional)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse(".2");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::real, ".2", 0));
    ++it;
    ASSERT_EQ(it, std::default_sentinel);
}

TEST(lexer, float_literal_only_integral)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("4.");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::real, "4.", 0));
    ++it;
    ASSERT_EQ(it, std::default_sentinel);
}

TEST(lexer, float_literal_integral_and_exponent)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("4e2");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::real, "4e2", 0));
    ++it;
    ASSERT_EQ(it, std::default_sentinel);
}

TEST(lexer, float_literal_integral_and_positive_exponent)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("4e+2");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::real, "4e+2", 0));
    ++it;
    ASSERT_EQ(it, std::default_sentinel);
}

TEST(lexer, float_literal_integral_and_negative_exponent)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("4e-2");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::real, "4e-2", 0));
    ++it;
    ASSERT_EQ(it, std::default_sentinel);
}

TEST(lexer, float_literal_integral_dot_and_exponent)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("4.e2");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::real, "4.e2", 0));
    ++it;
    ASSERT_EQ(it, std::default_sentinel);
}

TEST(lexer, float_literal_fractional_and_exponent)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse(".4e2");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::real, ".4e2", 0));
    ++it;
    ASSERT_EQ(it, std::default_sentinel);
}

TEST(lexer, float_literal_incomplete_exponent1)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("4e");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::error_incomplete_exponent, "4e", 0));
}

TEST(lexer, float_literal_incomplete_exponent2)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("4e+");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::error_incomplete_exponent, "4e+", 0));
}

TEST(lexer, hex_float_literal)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("0x4.2");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::real, "0x4.2", 0));
    ++it;
    ASSERT_EQ(it, std::default_sentinel);
}

TEST(lexer, hex_float_literal_only_fractional)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("0x.2");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::real, "0x.2", 0));
    ++it;
    ASSERT_EQ(it, std::default_sentinel);
}

TEST(lexer, hex_float_literal_only_integral)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("0x4.");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::real, "0x4.", 0));
    ++it;
    ASSERT_EQ(it, std::default_sentinel);
}

TEST(lexer, hex_float_literal_integral_and_exponent)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("0x4p2");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::real, "0x4p2", 0));
    ++it;
    ASSERT_EQ(it, std::default_sentinel);
}

TEST(lexer, hex_float_literal_integral_and_positive_exponent)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("0x4p+2");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::real, "0x4p+2", 0));
    ++it;
    ASSERT_EQ(it, std::default_sentinel);
}

TEST(lexer, hex_float_literal_integral_and_negative_exponent)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("0x4p-2");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::real, "0x4p-2", 0));
    ++it;
    ASSERT_EQ(it, std::default_sentinel);
}

TEST(lexer, hex_float_literal_integral_dot_and_exponent)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("0x4.p2");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::real, "0x4.p2", 0));
    ++it;
    ASSERT_EQ(it, std::default_sentinel);
}

TEST(lexer, hex_float_literal_fractional_and_exponent)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("0x.4p2");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::real, "0x.4p2", 0));
    ++it;
    ASSERT_EQ(it, std::default_sentinel);
}

TEST(lexer, hex_float_literal_incomplete_exponent1)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("0x4p");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::error_incomplete_exponent, "0x4p", 0));
}

TEST(lexer, hex_float_literal_incomplete_exponent2)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("0x4p+");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::error_incomplete_exponent, "0x4p+", 0));
}

TEST(lexer, dqstring_literal)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("\"foo\"");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::dstr, "foo", 0));
    ++it;
    ASSERT_EQ(it, std::default_sentinel);
}

TEST(lexer, sqstring_literal)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("\'foo\'");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::sstr, "foo", 0));
    ++it;
    ASSERT_EQ(it, std::default_sentinel);
}

TEST(lexer, dqstring_literal_empty)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("\"\"");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::dstr, "", 0));
    ++it;
    ASSERT_EQ(it, std::default_sentinel);
}

TEST(lexer, dqstring_literal_escaped_dquote)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("\"foo\\\"bar\"");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::dstr, "foo\\\"bar", 0));
    ++it;
    ASSERT_EQ(it, std::default_sentinel);
}

TEST(lexer, dqstring_literal_unicode)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("\"föö\"");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::dstr, "föö", 0));
    ++it;
    ASSERT_EQ(it, std::default_sentinel);
}

TEST(lexer, dqstring_literal_incomplete)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("\"foo");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::error_incomplete_string, "foo", 0));
}

TEST(lexer, line_comment)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("//foo\n");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::lcomment, "foo", 0));
    ++it;
    ASSERT_EQ(it, std::default_sentinel);
}

TEST(lexer, line_comment_unicode)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("//föö\n");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::lcomment, "föö", 0));
    ++it;
    ASSERT_EQ(it, std::default_sentinel);
}


TEST(lexer, line_comment_eof)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("//foo");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::lcomment, "foo", 0));
    ++it;
    ASSERT_EQ(it, std::default_sentinel);
}

TEST(lexer, line_comment_eof_unicode)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("//föö");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::lcomment, "föö", 0));
    ++it;
    ASSERT_EQ(it, std::default_sentinel);
}

TEST(lexer, block_comment)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("/*foo*/");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::bcomment, "foo", 0));
    ++it;
    ASSERT_EQ(it, std::default_sentinel);
}

TEST(lexer, block_comment_unicode)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("/*föö*/");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::bcomment, "föö", 0));
    ++it;
    ASSERT_EQ(it, std::default_sentinel);
}


TEST(lexer, block_comment_multi_line)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("/*foo\nbar*/");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::bcomment, "foo\nbar", 0));
    ++it;
    ASSERT_EQ(it, std::default_sentinel);
}

TEST(lexer, block_comment_star)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("/*foo*bar*/");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::bcomment, "foo*bar", 0));
    ++it;
    ASSERT_EQ(it, std::default_sentinel);
}

TEST(lexer, block_comment_star_end)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("/*foo**/");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::bcomment, "foo*", 0));
    ++it;
    ASSERT_EQ(it, std::default_sentinel);
}

TEST(lexer, block_comment_incomplete)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("/*foo");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::error_incomplete_comment, "foo", 0));
}

TEST(lexer, identifier)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("foo");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::id, "foo", 0));
    ++it;
    ASSERT_EQ(it, std::default_sentinel);
}

TEST(lexer, identifier_with_number)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("f42");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::id, "f42", 0));
    ++it;
    ASSERT_EQ(it, std::default_sentinel);
}

TEST(lexer, identifier_with_a31)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("föö");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::id, "föö", 0));
    ++it;
    ASSERT_EQ(it, std::default_sentinel);
}

TEST(lexer, identifier_start_a31)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("ööf");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::id, "ööf", 0));
    ++it;
    ASSERT_EQ(it, std::default_sentinel);
}

TEST(lexer, other_slash)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("/");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::other, "/", 0));
    ++it;
    ASSERT_EQ(it, std::default_sentinel);
}

TEST(lexer, other_patern_syntax)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("∑");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::other, "∑", 0));
    ++it;
    ASSERT_EQ(it, std::default_sentinel);
}

TEST(lexer, ini_assignment_ini_string)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::ini_style()>{};

    auto it = c_lexer.parse("foo = bar");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::id, "foo", 0));
    ++it;
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::other, "=", 4));
    ++it;
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::istr, "bar", 6));
    ++it;
    ASSERT_EQ(it, std::default_sentinel);
}




TEST(lexer, multiple_tokens)
{
    constexpr auto c_lexer = hi::detail::lexer<hi::lexer_config::c_style()>{};

    auto it = c_lexer.parse("1234, 1.23, \"hello\", foo;");
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::integer, "1234", 0));
    ++it;
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::other, ",", 4));
    ++it;
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::real, "1.23", 6));
    ++it;
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::other, ",", 10));
    ++it;
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::dstr, "hello", 12));
    ++it;
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::other, ",", 19));
    ++it;
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::id, "foo", 21));
    ++it;
    ASSERT_EQ(*it, hi::lexer_token_type(hi::lexer_token_kind::other, ";", 24));
    ++it;
    ASSERT_EQ(it, std::default_sentinel);
}
