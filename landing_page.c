#include <gtk/gtk.h>
#include <gdk/gdk.h>

typedef struct {
    GtkWidget *window;
    GtkWidget *main_container;
    GtkWidget *hero_section;
    GtkWidget *features_section;
    GtkWidget *footer_section;
    GtkWidget *get_started_button;
} AppWidgets;

static void create_hero_section(AppWidgets *app);
static void create_features_section(AppWidgets *app);
static void create_footer_section(AppWidgets *app);
static void apply_styles(AppWidgets *app);
static void on_get_started_clicked(GtkWidget *widget, gpointer data);
static void on_window_destroy(GtkWidget *widget, gpointer data);
static gboolean on_button_enter(GtkWidget *widget, GdkEventCrossing *event, gpointer data);
static gboolean on_button_leave(GtkWidget *widget, GdkEventCrossing *event, gpointer data);

static const char *css_styles = 
    "window {"
    "  background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);"
    "  font-family: 'Segoe UI', 'Roboto', sans-serif;"
    "}"
    ""
    ".hero-container {"
    "  background: rgba(255, 255, 255, 0.05);"
    "  border-radius: 20px;"
    "  margin: 40px;"
    "  padding: 60px 40px;"
    "  box-shadow: 0 20px 40px rgba(0, 0, 0, 0.1);"
    "}"
    ""
    ".hero-title {"
    "  font-size: 48px;"
    "  font-weight: bold;"
    "  color: #ffffff;"
    "  text-shadow: 2px 2px 4px rgba(0, 0, 0, 0.3);"
    "  margin-bottom: 20px;"
    "}"
    ""
    ".hero-subtitle {"
    "  font-size: 20px;"
    "  color: #e8e8e8;"
    "  margin-bottom: 40px;"
    "  line-height: 1.6;"
    "}"
    ""
    ".get-started-btn {"
    "  background: linear-gradient(45deg, #ff6b6b, #ee5a24);"
    "  color: white;"
    "  border: none;"
    "  border-radius: 50px;"
    "  padding: 16px 40px;"
    "  font-size: 18px;"
    "  font-weight: bold;"
    "  text-shadow: 1px 1px 2px rgba(0, 0, 0, 0.2);"
    "  box-shadow: 0 8px 20px rgba(255, 107, 107, 0.4);"
    "  transition: all 0.3s ease;"
    "}"
    ""
    ".get-started-btn:hover {"
    "  background: linear-gradient(45deg, #ff5252, #d63031);"
    "  transform: translateY(-2px);"
    "  box-shadow: 0 12px 25px rgba(255, 107, 107, 0.6);"
    "}"
    ""
    ".features-container {"
    "  margin: 0 40px 40px 40px;"
    "}"
    ""
    ".features-title {"
    "  font-size: 36px;"
    "  font-weight: bold;"
    "  color: #ffffff;"
    "  text-align: center;"
    "  margin-bottom: 40px;"
    "  text-shadow: 2px 2px 4px rgba(0, 0, 0, 0.3);"
    "}"
    ""
    ".feature-card {"
    "  background: rgba(255, 255, 255, 0.1);"
    "  border-radius: 15px;"
    "  padding: 30px 25px;"
    "  margin: 15px;"
    "  backdrop-filter: blur(10px);"
    "  border: 1px solid rgba(255, 255, 255, 0.1);"
    "  box-shadow: 0 8px 32px rgba(0, 0, 0, 0.1);"
    "  transition: transform 0.3s ease;"
    "}"
    ""
    ".feature-card:hover {"
    "  transform: translateY(-5px);"
    "  box-shadow: 0 15px 40px rgba(0, 0, 0, 0.2);"
    "}"
    ""
    ".feature-icon {"
    "  font-size: 48px;"
    "  color: #ffd700;"
    "  margin-bottom: 20px;"
    "  text-shadow: 2px 2px 4px rgba(0, 0, 0, 0.3);"
    "}"
    ""
    ".feature-title {"
    "  font-size: 22px;"
    "  font-weight: bold;"
    "  color: #ffffff;"
    "  margin-bottom: 15px;"
    "}"
    ""
    ".feature-description {"
    "  font-size: 16px;"
    "  color: #e0e0e0;"
    "  line-height: 1.5;"
    "}"
    ""
    ".footer-container {"
    "  background: rgba(0, 0, 0, 0.2);"
    "  padding: 20px;"
    "  border-top: 1px solid rgba(255, 255, 255, 0.1);"
    "}"
    ""
    ".footer-text {"
    "  font-size: 14px;"
    "  color: #b0b0b0;"
    "  text-align: center;"
    "}";

int main(int argc, char *argv[]) {
    AppWidgets app = {0};
    
    gtk_init(&argc, &argv);
    
    app.window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(app.window), "Modern Landing Page");
    gtk_window_set_default_size(GTK_WINDOW(app.window), 1200, 900);
    gtk_window_set_position(GTK_WINDOW(app.window), GTK_WIN_POS_CENTER);
    gtk_window_set_resizable(GTK_WINDOW(app.window), TRUE);
    
    g_signal_connect(app.window, "destroy", G_CALLBACK(on_window_destroy), NULL);
    
    GtkWidget *scrolled = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled), 
                                   GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
    gtk_container_add(GTK_CONTAINER(app.window), scrolled);
    
    app.main_container = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(scrolled), app.main_container);
    
    apply_styles(&app);
    
    create_hero_section(&app);
    create_features_section(&app);
    create_footer_section(&app);
    
    gtk_widget_show_all(app.window);
    
    gtk_main();
    
    return 0;
}

static void create_hero_section(AppWidgets *app) {
    app->hero_section = gtk_box_new(GTK_ORIENTATION_VERTICAL, 20);
    gtk_widget_set_halign(app->hero_section, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(app->hero_section, GTK_ALIGN_CENTER);
    gtk_style_context_add_class(gtk_widget_get_style_context(app->hero_section), "hero-container");
    
    GtkWidget *hero_title = gtk_label_new("Welcome to the Future");
    gtk_widget_set_halign(hero_title, GTK_ALIGN_CENTER);
    gtk_style_context_add_class(gtk_widget_get_style_context(hero_title), "hero-title");
    
    GtkWidget *hero_subtitle = gtk_label_new(
        "Experience next-generation technology that transforms\n"
        "the way you work, create, and connect with the world."
    );
    gtk_widget_set_halign(hero_subtitle, GTK_ALIGN_CENTER);
    gtk_label_set_justify(GTK_LABEL(hero_subtitle), GTK_JUSTIFY_CENTER);
    gtk_style_context_add_class(gtk_widget_get_style_context(hero_subtitle), "hero-subtitle");
    
    app->get_started_button = gtk_button_new_with_label("Get Started");
    gtk_widget_set_halign(app->get_started_button, GTK_ALIGN_CENTER);
    gtk_style_context_add_class(gtk_widget_get_style_context(app->get_started_button), "get-started-btn");
    
    g_signal_connect(app->get_started_button, "clicked", G_CALLBACK(on_get_started_clicked), app);
    g_signal_connect(app->get_started_button, "enter-notify-event", G_CALLBACK(on_button_enter), NULL);
    g_signal_connect(app->get_started_button, "leave-notify-event", G_CALLBACK(on_button_leave), NULL);
    
    gtk_box_pack_start(GTK_BOX(app->hero_section), hero_title, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(app->hero_section), hero_subtitle, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(app->hero_section), app->get_started_button, FALSE, FALSE, 0);
    
    gtk_box_pack_start(GTK_BOX(app->main_container), app->hero_section, FALSE, FALSE, 0);
}

static void create_features_section(AppWidgets *app) {
    app->features_section = gtk_box_new(GTK_ORIENTATION_VERTICAL, 30);
    gtk_style_context_add_class(gtk_widget_get_style_context(app->features_section), "features-container");
    
    GtkWidget *features_title = gtk_label_new("Powerful Features");
    gtk_style_context_add_class(gtk_widget_get_style_context(features_title), "features-title");
    gtk_box_pack_start(GTK_BOX(app->features_section), features_title, FALSE, FALSE, 0);
    
    GtkWidget *features_grid = gtk_grid_new();
    gtk_grid_set_column_homogeneous(GTK_GRID(features_grid), TRUE);
    gtk_grid_set_column_spacing(GTK_GRID(features_grid), 20);
    gtk_grid_set_row_spacing(GTK_GRID(features_grid), 20);
    gtk_widget_set_halign(features_grid, GTK_ALIGN_CENTER);
    gtk_widget_set_hexpand(features_grid, TRUE);
    
    struct {
        const char *icon;
        const char *title;
        const char *description;
    } features[] = {
        {"680", "Lightning Fast", "Experience blazing fast performance with our optimized algorithms and cutting-edge technology."},
        {"512", "Secure & Private", "Your data is protected with enterprise-grade security and end-to-end encryption."},
        {"3a8", "Beautiful Design", "Enjoy a stunning user interface that's both intuitive and visually appealing."}
    };
    
    for (int i = 0; i < 3; i++) {
        GtkWidget *card = gtk_box_new(GTK_ORIENTATION_VERTICAL, 15);
        gtk_widget_set_halign(card, GTK_ALIGN_CENTER);
        gtk_widget_set_valign(card, GTK_ALIGN_START);
        gtk_style_context_add_class(gtk_widget_get_style_context(card), "feature-card");
        
        GtkWidget *icon = gtk_label_new(features[i].icon);
        gtk_widget_set_halign(icon, GTK_ALIGN_CENTER);
        gtk_style_context_add_class(gtk_widget_get_style_context(icon), "feature-icon");
        
        GtkWidget *title = gtk_label_new(features[i].title);
        gtk_widget_set_halign(title, GTK_ALIGN_CENTER);
        gtk_style_context_add_class(gtk_widget_get_style_context(title), "feature-title");
        
        GtkWidget *description = gtk_label_new(features[i].description);
        gtk_label_set_line_wrap(GTK_LABEL(description), TRUE);
        gtk_label_set_line_wrap_mode(GTK_LABEL(description), PANGO_WRAP_WORD);
        gtk_label_set_max_width_chars(GTK_LABEL(description), 40);
        gtk_widget_set_halign(description, GTK_ALIGN_CENTER);
        gtk_label_set_justify(GTK_LABEL(description), GTK_JUSTIFY_CENTER);
        gtk_style_context_add_class(gtk_widget_get_style_context(description), "feature-description");
        
        gtk_box_pack_start(GTK_BOX(card), icon, FALSE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(card), title, FALSE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(card), description, FALSE, FALSE, 0);
        
        gtk_grid_attach(GTK_GRID(features_grid), card, i, 0, 1, 1);
    }
    
    gtk_box_pack_start(GTK_BOX(app->features_section), features_grid, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(app->main_container), app->features_section, FALSE, FALSE, 0);
}

static void create_footer_section(AppWidgets *app) {
    app->footer_section = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_style_context_add_class(gtk_widget_get_style_context(app->footer_section), "footer-container");
    
    GtkWidget *copyright = gtk_label_new(" a9 2024 Modern Landing Page. All rights reserved. Built with GTK and C.");
    gtk_style_context_add_class(gtk_widget_get_style_context(copyright), "footer-text");
    
    gtk_box_pack_start(GTK_BOX(app->footer_section), copyright, FALSE, FALSE, 0);
    gtk_box_pack_end(GTK_BOX(app->main_container), app->footer_section, FALSE, FALSE, 0);
}

static void apply_styles(AppWidgets *app) {
    GtkCssProvider *css_provider = gtk_css_provider_new();
    GdkDisplay *display = gdk_display_get_default();
    GdkScreen *screen = gdk_display_get_default_screen(display);
    
    gtk_css_provider_load_from_data(css_provider, css_styles, -1, NULL);
    
    gtk_style_context_add_provider_for_screen(screen,
                                             GTK_STYLE_PROVIDER(css_provider),
                                             GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    
    g_object_unref(css_provider);
}

static void on_get_started_clicked(GtkWidget *widget, gpointer data) {
    GtkWidget *dialog = gtk_message_dialog_new(NULL,
                                             GTK_DIALOG_MODAL,
                                             GTK_MESSAGE_INFO,
                                             GTK_BUTTONS_OK,
                                             "Welcome! 389\n\nYou clicked the Get Started button!\nThis is where you would typically redirect users to sign up or learn more.");
    
    gtk_window_set_title(GTK_WINDOW(dialog), "Welcome");
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

static void on_window_destroy(GtkWidget *widget, gpointer data) {
    gtk_main_quit();
}

static gboolean on_button_enter(GtkWidget *widget, GdkEventCrossing *event, gpointer data) {
    return FALSE;
}

static gboolean on_button_leave(GtkWidget *widget, GdkEventCrossing *event, gpointer data) {
    return FALSE;
}